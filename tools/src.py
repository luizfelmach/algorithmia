#!/usr/bin/python

import os
import re
import utils


def pattern_extension(kind):
    if kind in ["c", "cc", "cpp", "h", "java"]:
        return r"\s*//\s*NOTEBOOK\b(.*?)\s*//\s*NOTEBOOK\b"
    if kind in ["py"]:
        return r"\s*#\s*NOTEBOOK\b(.*?)\s*#\s*NOTEBOOK\b"
    return None


def file_filter(content, pattern):
    res = re.findall(pattern, content, re.DOTALL)
    if len(res) == 0:
        return content

    content = ""
    for i in res:
        content += i

    return content


def generate_content(filename):
    content = utils.file_content(filename)
    ext = utils.file_ext(filename)
    pattern = pattern_extension(ext)

    if not pattern:
        return content

    return file_filter(content, pattern)


def build(sections, build_path):
    files = [x for s in sections for x in s.files()]
    directories = [f"{build_path}/{os.path.dirname(x)}" for x in files]

    utils.make_directories([build_path])
    utils.make_directories(directories)

    for filename in files:
        b_filename = f"{build_path}/{filename}"
        content = generate_content(filename)
        with open(b_filename, "w") as stream:
            stream.write(content)
