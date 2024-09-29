#!/usr/bin/python

import sys
import yaml
from utils import file_exists
from schema import Schema, Use, And, SchemaError


def parse_schema(data):
    SCHEMA = Schema({str: [{str: And(str, Use(file_exists))}]})
    validated = SCHEMA.validate(data)
    return validated


def flatten_data(data):
    data = list(data.items())
    data = map(lambda x: (x[0], list(map(lambda y: list(y.items())[0], x[1]))), data)
    data = list(data)
    return data


def load(content_path):
    with open(content_path) as file:
        content = yaml.safe_load(file)
        data = parse_schema(content)
        structure = flatten_data(data)
    return structure


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"usage: python {sys.argv[0]} <content_path>")
        exit(1)
    structure = load(sys.argv[1])
    print(structure)
