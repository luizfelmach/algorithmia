#!/usr/bin/python
# This script was based in the file of the Stanford University ACM team

# sudo pacman -S texlive-binextra texlive-latexextra texlive-fontsextra 

import os
import yaml
from schema import Schema, Use, And, SchemaError 
import subprocess
import re

CONTENT = "content.yaml"
BUILD_DIR = "./.build"


def isfile(p):
  if not os.path.isfile(p):
    raise SchemaError(f"File {p} not exists.")
  return p

SCHEMA = Schema({
  str: [
    {
      str: And(str, Use(isfile))
    }
  ]
})

def load_content():
  with open(CONTENT) as stream:
    try:
      content = yaml.safe_load(stream)
      validated = SCHEMA.validate(content)
      return validated
    except SchemaError as e:
      print(repr(e))
      exit(1)

def get_style(filename):
  ext = filename.lower().split('.')[-1]
  if ext in ['c', 'cc', 'cpp', 'h']:
    return 'cpp'
  elif ext in ['java']:
    return 'java'
  elif ext in ['py']:
    return 'py'
  elif ext in ['tex']:
    return 'tex'
  else:
    return 'txt'


def get_tex_section(section_name, subsections):
  tex = '\\section{%s}\n' % section_name
  for [subsection_name, filename] in subsections:
    tex += '\\subsection{%s}\n' % subsection_name
    if(get_style(filename) == 'tex'):
      tex += '\\raggedbottom{\\input{%s}}\n' % filename
    else:
      tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s}\n' % (get_style(filename), f"{BUILD_DIR}/{filename}")
    tex += '\\hrulefill\n'
  tex += '\n'
  return tex

def file_content(file):
  with open(file) as stream:
    return stream.read()

def file_filter(file_content):
  pattern = r"#define NOTEBOOK(.*?)#define NOTEBOOK"
  res = re.findall(pattern, file_content, re.DOTALL)
  if len(res) == 0: return file_content
  return res[0]
  

if __name__ == "__main__":
  content = load_content()
  content = list(content.items())
  content = map(lambda x: (x[0], list(map(lambda y: list(y.items())[0], x[1]))), content)
  content = list(content)
  files = map(lambda x: x[1], content)
  files = map(lambda x: x[1], [item for sub in files for item in sub])
  files = list(files)

  if not os.path.isdir(BUILD_DIR): os.mkdir(BUILD_DIR)

  for file in files:
    ffile = f'{BUILD_DIR}/{file}'
    raw = file_content(file)
    raw = file_filter(raw)
    if not os.path.isdir(os.path.dirname(ffile)): os.makedirs(os.path.dirname(ffile))
    with open(ffile, "w") as stream:
      stream.write(raw)

  tex = ''
  for section in content:
    tex += get_tex_section(section[0], section[1])
    
  with open('contents.tex', 'w') as f:
    f.write(tex)
  
  subprocess.run(['pdflatex', '-interaction=nonstopmode', 'model/notebook.tex'])
  os.system("mv notebook.pdf algorithms.pdf")
  os.system("rm contents.tex")
  os.system("rm notebook.*")
  os.system(f"rm {BUILD_DIR}")
