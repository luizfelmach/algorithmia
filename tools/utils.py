import os


def file_exists(file_path):
    if not os.path.isfile(file_path):
        raise FileNotFoundError(f"File {file_path} not exists.")
    return file_path


def file_ext(filename):
    ext = filename.lower().split(".")[-1]
    return ext
