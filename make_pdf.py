#!/usr/bin/python
# This script was based in the file of the Stanford University ACM team
# Packages (archlinux): texlive-binextra texlive-latexextra texlive-fontsextra

import os
import sys
import subprocess

sys.path.append(os.path.join(os.path.dirname(__file__), "tools"))

import content
import src

BUILD = ".build"
CONTENT = "content.yaml"
MODEL = "model/notebook.tex"

if __name__ == "__main__":

    sections = content.load(CONTENT)
    src.build(sections, BUILD)

    tex = ""
    for section in sections:
        tex += section.tex(BUILD)

    with open("contents.tex", "w") as f:
        f.write(tex)

    subprocess.run(
        [
            "latexmk",
            "-pdf",
            "-interaction=nonstopmode",
            MODEL,
        ]
    )

    os.system("mv notebook.pdf algorithms.pdf")
    os.system(f"rm -r contents.tex notebook.* {BUILD}")
