#!/usr/bin/env python3

"""
|-------------+----------------------------------------------------------|
| TITLE       | SolveHR.py                                               |
| DESCRIPTION | Fetches problem statement and initializes an answer file |
|             | with a template code for selected programming language.  |
|             | The default language is C++14 (corresponding to -l cc).  |
| AUTHOR      | simba (szczerbiakadam@gmail.com)                         |
| DATE        | 23-11-2016                                               |
| VERSION     | 0.3                                                      |
| EXAMPLES    | SolveHR.py SolveMeFirst \                                |
|             |     https://www.hackerrank.com/challenges/solve-me-first |
|-------------+----------------------------------------------------------|
"""

import os
import sys
import argparse
import datetime


LANGS = {
    "c" : {
        "NAME" : "ANSI C",
        "SHEBANG" : None,
        "OPENING_MULTILINE_COMMENT" : "/*",
        "CLOSING_MULTILINE_COMMENT" : "*/",
        "SKELETON_CODE" : [
                "#include <stdio.h>", "", "",
                "int main()", "{", "  int T, t;", "  scanf(\"%d\", &T);",
                "  for(t = 0; t < T; ++t)",
                "  {", "  }", "", "  return 0;", "}",
        ],
    },
    "cc" : {
        "NAME" : "C++14",
        "SHEBANG" : None,
        "OPENING_MULTILINE_COMMENT" : "/*",
        "CLOSING_MULTILINE_COMMENT" : "*/",
        "SKELETON_CODE" : [
                "#include <iostream>", "", "",
                "int main(int argc, char **argv)", "{",
                "  int T;",
                "  std::cin >> T;", "",
                "  for (int t = 0; t < T; ++t)",
                "  {", "  }", "", "  return 0;", "}",
         ],
    },
    "py" : {
        "NAME" : "Python 3",
        "SHEBANG" : "#!/usr/bin/env python3",
        "OPENING_MULTILINE_COMMENT" : "\"\"\"",
        "CLOSING_MULTILINE_COMMENT" : "\"\"\"",
        "SKELETON_CODE" : [
                "def main():",
                "    for t in range(int(input())):",
                "        pass", "", "",
                "if (__name__ == \"__main__\"):",
                "    main()",
        ],
    }
}

HR_DIRECTORY = os.path.expanduser("~/Source/Learning/HackerRank/")


# Prepares the argument parser:
def init_argparse():
    parser = argparse.ArgumentParser()
    parser.add_argument("title", help="title of the problem statement")
    parser.add_argument("link", help="link to the problem statement site")
    parser.add_argument("-l", "--lang",
            choices=list(LANGS.keys()),
            help="language to be used for solving the challenge")

    return parser


def create_solution_file(full_file_name, args):
    selected_lang = LANGS[args.lang]

    # If the solution file exists already, it will not be overwritten:
    if os.path.isfile(full_file_name):
        print("File %s exists already - not overwriting." % (full_file_name,))
        return

    # Holds the consecutive lines of the initial answer file:
    lines = []

    # Adds the shebang instruction followed by the blank line
    # where applicable:
    if (selected_lang["SHEBANG"] is not None):
        lines.append(selected_lang["SHEBANG"])
        lines.append("")

    # Adds the opening line of the header comment:
    lines.append(selected_lang["OPENING_MULTILINE_COMMENT"])

    # Adds the first line of the header comment:
    line = "Solution to the \"" + args.title + "\" challenge by HackerRank:"
    lines.append(line)

    # Adds the challenge hyperlink:
    lines.append(args.link)

    # Adds the "written on {DATE} in {LANG}":
    line = "Written on " + datetime.datetime.today().strftime("%d-%m-%Y") \
            + " in " + selected_lang["NAME"]
    lines.append(line)

    # Adds the author's signature:
    lines.append("by simba (szczerbiakadam@gmail.com)")

    # Adds the MIT license information:
    lines.append("License: MIT")

    # Adds the closing line of the header comment:
    lines.append(selected_lang["CLOSING_MULTILINE_COMMENT"])

    # Inserts the skeleton code:
    lines.append("")
    lines.append("")
    for entry in selected_lang["SKELETON_CODE"]:
        lines.append(entry)


    # Writes out the prepared solution to the file:
    solution_file = open(full_file_name, "w")
    for line in lines:
        solution_file.write("%s\n" % (line,))
    solution_file.close()


def main():
    parser = init_argparse()
    args = parser.parse_args()
    if args.lang is None:
        args.lang = "cc"
    print("Chosen language: %s" % (LANGS[args.lang]["NAME"],))

    # Makes sure that the directory for a solution exists:
    challenge_directory = os.path.join(HR_DIRECTORY, args.title)
    os.makedirs(challenge_directory, exist_ok=True)

    solution_file_name = os.path.join(challenge_directory,
            args.title + "." + args.lang)

    # TODO: Add problem statement fetching (the PDF file)

    # Prepares the initial solution file:
    create_solution_file(solution_file_name, args)

    print("Press any key to start the editor (Ctrl-C to bail out):")
    input()

    # Finally opens the created solution file in the editor:
    os.system("vim " + solution_file_name)

if __name__ == "__main__":
    main()
