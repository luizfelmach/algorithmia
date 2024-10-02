from utils import file_ext


class Subsection:
    def __init__(self, title: str, path: str):
        self.title = title
        self.path = path
        self.range = self.ranges()

    def ranges(self):
        with open(self.path, "r") as file:
            lines = file.readlines()

        ranges = []
        lines_tags = []

        for i, line in enumerate(lines, start=1):
            if "// NOTEBOOK" in line or "# NOTEBOOK" in line:
                lines_tags.append(i)

        if len(lines_tags) == 0 or len(lines_tags) % 2 == 1:
            return [(1, len(lines))]

        for i in range(0, len(lines_tags), 2):
            ranges.append((lines_tags[i] + 1, lines_tags[i + 1] - 1))

        return ranges

    def range_text(self):
        text = ""
        i = 0
        for r in self.range:
            text += f"{r[0]}-{r[1]}"
            i += 1
            if i < len(self.range):
                text += ","
        return text

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

    def tex(self):
        tex = "\\subsection{%s}\n" % self.title
        style = self.style()

        if style == "tex":
            tex += "\\raggedbottom{\\input{%s}}\n" % self.path
            tex += "\\hrulefill\n"
            return tex

        tex += "\\raggedbottom\\lstinputlisting[style=%s, linerange={%s}]{%s}\n" % (
            style,
            self.range_text(),
            self.path,
        )
        tex += "\\hrulefill\n"
        return tex


class Section:
    def __init__(self, title: str):
        self.title = title
        self.subsections = []

    def append(self, subsection: Subsection):
        self.subsections.append(subsection)

    def tex(self):
        tex = "\\section{%s}\n" % self.title
        for subsection in self.subsections:
            tex += subsection.tex()
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

    print(section.tex())
