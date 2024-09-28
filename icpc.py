#!/usr/bin/python
# This script was based in the file of the Stanford University ACM team

# sudo pacman -S texlive-binextra texlive-latexextra texlive-fontsextra

import subprocess
import os
import re
import yaml
from schema import Schema, Use, And, SchemaError

CONTENT = "content.yaml"
BUILD = "./.build"


def file_exists(p):
    if not os.path.isfile(p):
        raise SchemaError(f"File {p} not exists.")
    return p


SCHEMA = Schema({str: [{str: And(str, Use(file_exists))}]})


def load_content():
    with open(CONTENT) as stream:
        try:
            content = yaml.safe_load(stream)
            validated = SCHEMA.validate(content)
            validated = list(validated.items())
            validated = map(
                lambda x: (x[0], list(map(lambda y: list(y.items())[0], x[1]))),
                validated,
            )
            validated = list(validated)
            return validated
        except SchemaError as e:
            print(repr(e))
            exit(1)
    

def build_filename(filename):
    return f"{BUILD}/{filename}"


def load_builds(files):
    dirs = [f"{BUILD}/{os.path.dirname(x)}" for x in files]
    return dirs


def load_files(content):
    files = map(lambda x: x[1], content)
    files = map(lambda x: x[1], [item for sub in files for item in sub])
    files = list(files)
    return files


def filename_extension(filename):
    ext = filename.lower().split(".")[-1]
    if ext in ["c", "cc", "cpp", "h"]:
        return "cpp"
    elif ext in ["java"]:
        return "java"
    elif ext in ["py"]:
        return "py"
    elif ext in ["tex"]:
        return "tex"
    else:
        return "txt"


def get_tex_section(section_name, subsections):
    tex = "\\section{%s}\n" % section_name
    for [subsection_name, filename] in subsections:
        tex += "\\subsection{%s}\n" % subsection_name
        if filename_extension(filename) == "tex":
            tex += "\\raggedbottom{\\input{%s}}\n" % filename
        else:
            tex += "\\raggedbottom\\lstinputlisting[style=%s]{%s}\n" % (
                filename_extension(filename),
                f"{BUILD}/{filename}",
            )
        tex += "\\hrulefill\n"
    tex += "\n"
    return tex


def file_content(file: list[str]):
    with open(file) as stream:
        return stream.read()


def pattern_file(kind):
    if kind in ["c", "cc", "cpp", "h", "java"]:
        return r"\s*//\s*NOTEBOOK\b(.*?)\s*//\s*NOTEBOOK\b"
    if kind in ["py"]:
        return r"\s*#\s*NOTEBOOK\b(.*?)\s*#\s*NOTEBOOK\b"
    return None


def file_filter(content, kind):
    pattern = pattern_file(kind)
    if not pattern:
        return content

    res = re.findall(pattern, content, re.DOTALL)
    if len(res) == 0:
        return content

    content = ''
    for i in res:
        content += i
    
    return content


def make_dirs(dirs):
    for dir in dirs:
        if not os.path.isdir(dir):
            os.makedirs(dir)


if __name__ == "__main__":
    content = load_content()
    files = load_files(content)
    dirs = load_builds(files)

    make_dirs([BUILD])
    make_dirs(dirs)

    for filename in files:
        b_filename = build_filename(filename)
        ext = filename_extension(filename)
        file = file_content(filename)
        file = file_filter(file, ext)

        with open(b_filename, "w") as stream:
            stream.write(file)

    tex = ""
    for section in content:
        tex += get_tex_section(section[0], section[1])

    
    with open("contents.tex", "w") as f:
        f.write(tex)

    subprocess.run(["latexmk", "-pdf", "-interaction=nonstopmode", "model/notebook.tex"])
    os.system("mv notebook.pdf algorithms.pdf")
    os.system("rm contents.tex")
    os.system("rm notebook.*")
    os.system(f"rm -r {BUILD}")
