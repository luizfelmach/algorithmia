#!/usr/bin/python
# This script was based in the file of the Stanford University ACM team
# Packages (archlinux): texlive-binextra texlive-latexextra texlive-fontsextra

import os
import sys
import subprocess
import content
import src
from utils import filename_extension

BUILD = ".build"


def style(filename):
    ext = filename_extension(filename)
    if ext in ["c", "cc", "cpp", "h"]:
        return "cpp"
    if ext in ["java"]:
        return "java"
    if ext in ["py"]:
        return "py"
    if ext in ["tex"]:
        return "tex"
    return "txt"


def get_tex_section(section_name, subsections):
    tex = "\\section{%s}\n" % section_name
    for [subsection_name, filename] in subsections:
        tex += "\\subsection{%s}\n" % subsection_name
        if style(filename) == "tex":
            tex += "\\raggedbottom{\\input{%s}}\n" % filename
        else:
            tex += "\\raggedbottom\\lstinputlisting[style=%s]{%s}\n" % (
                style(filename),
                f"{BUILD}/{filename}",
            )
        tex += "\\hrulefill\n"
    tex += "\n"
    return tex


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"usage: {sys.argv[0]} <content_path> <notebook.tex>")
        exit(1)

    structure = content.load(sys.argv[1])
    src.build(structure, BUILD)

    tex = ""
    for section in structure:
        tex += get_tex_section(section[0], section[1])

    with open("contents.tex", "w") as f:
        f.write(tex)

    subprocess.run(["latexmk", "-pdf", "-interaction=nonstopmode", sys.argv[2]])
    os.system("mv notebook.pdf algorithms.pdf")
    os.system("rm contents.tex")
    os.system("rm notebook.*")
    os.system(f"rm -r {BUILD}")
