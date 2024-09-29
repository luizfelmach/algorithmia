from utils import file_ext


class Subsection:
    def __init__(self, title: str, path: str):
        self.title = title
        self.path = path

    def style(self):
        ext = file_ext(self.path)
        style_map = {
            "c": "cpp",
            "cc": "cpp",
            "cpp": "cpp",
            "h": "cpp",
            "java": "java",
            "py": "py",
            "tex": "tex",
        }
        return style_map.get(ext, "txt")

    def tex(self, path_ref):
        path = f"{path_ref}/{self.path}"
        tex = "\\subsection{%s}\n" % self.title
        style = self.style()

        if style == "tex":
            tex += "\\raggedbottom{\\input{%s}}\n" % path
            tex += "\\hrulefill\n"
            return tex

        tex += "\\raggedbottom\\lstinputlisting[style=%s]{%s}\n" % (style, path)
        tex += "\\hrulefill\n"
        return tex


class Section:
    def __init__(self, title: str):
        self.title = title
        self.subsections = []

    def append(self, subsection: Subsection):
        self.subsections.append(subsection)

    def tex(self, path_ref):
        tex = "\\section{%s}\n" % self.title
        for subsection in self.subsections:
            tex += subsection.tex(path_ref)
        tex += "\n"
        return tex

    def files(self):
        return [x.path for x in self.subsections]


if __name__ == "__main__":
    section = Section("C++")

    section.append(Subsection("DFS", "code/dfs.cpp"))
    section.append(Subsection("BFS", "code/bfs.cpp"))
    section.append(Subsection("Merge Sort", "code/merge_sort.cpp"))
    section.append(Subsection("Bellman-Ford", "code/bellman_ford.cpp"))
    section.append(Subsection("Draft", "code/bellman_ford.txt"))
    section.append(Subsection("Math", "code/math.tex"))

    # section.validate_files()

    print(section.tex())
