import os


def file_exists(file_path):
    if not os.path.isfile(file_path):
        raise FileNotFoundError(f"File {file_path} not exists.")
    return file_path


def file_content(file: list[str]):
    with open(file) as stream:
        return stream.read()


def make_directories(directories):
    for directory in directories:
        if not os.path.isdir(directory):
            os.makedirs(directory)


def file_ext(filename):
    ext = filename.lower().split(".")[-1]
    return ext
