#!/usr/bin/python

import sys
import yaml
from utils import file_exists
from section import Section, Subsection
from schema import (
    Schema,
    Use,
    And,
    SchemaError,
)


def parse_schema(data):
    SCHEMA = Schema({str: [{str: And(str, Use(file_exists))}]})
    validated = SCHEMA.validate(data)
    return validated


def flatten_data(data):
    items = list(data.items())
    sections = []
    for [title, subsections] in items:
        section = Section(title)
        for subsection in subsections:
            aux = list(subsection.items())
            section.append(Subsection(aux[0][0], aux[0][1]))
        sections.append(section)
    return sections


def load(content_path):
    with open(content_path) as file:
        content = yaml.safe_load(file)
        data = parse_schema(content)
        sections = flatten_data(data)
    return sections
