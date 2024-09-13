#!/usr/bin/python
# This script was based in the file of the Stanford University ACM team

# sudo pacman -S texlive-binextra texlive-latexextra texlive-fontsextra 

import os
import yaml
from schema import Schema, Use, And, SchemaError 
import subprocess

CONTENT = "content.yaml"

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
      tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s}\n' % (get_style(filename), filename)
    tex += '\\hrulefill\n'
  tex += '\n'
  return tex

def get_tex(sections):
  tex = ''
  for (section_name, subsections) in sections:
    tex += '\\section{%s}\n' % section_name
    for (filename, subsection_name) in subsections:
      tex += '\\subsection{%s}\n' % subsection_name
      if(get_style(filename) == 'tex'):
        tex += '\\raggedbottom{\\input{%s}}\n' % filename
      else:
        tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s}\n' % (get_style(filename), filename)
      tex += '\\hrulefill\n'
    tex += '\n'
  return tex

if __name__ == "__main__":
  content = load_content()
  content = list(content.items())
  content = map(lambda x: (x[0], list(map(lambda y: list(y.items())[0], x[1]))), content)

  tex = ''
  for section in content:
    tex += get_tex_section(section[0], section[1])
    
  with open('contents.tex', 'w') as f:
    f.write(tex)

  subprocess.run(['pdflatex', '-interaction=nonstopmode', 'model/notebook.tex'])
  os.system("mv notebook.pdf algorithms.pdf")
  os.system("rm contents.tex")
  os.system("rm notebook.*")
