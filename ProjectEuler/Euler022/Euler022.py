#!/usr/bin/env python

"""
Euler #022: Names Scores
"""

names = []


def read_names():
    global names
    N = int(input())
    for n in range(N):
        name = input()
        names.append(name)


def get_name_score(name):
    multiplier = names.index(name) + 1
    base_score = 0
    for letter in name:
        base_score += (ord(letter) - ord("A")) + 1

    return base_score * multiplier


def main():
    global names
    read_names()
    names.sort()

    Q = int(input())
    for q in range(Q):
        query = input()
        score = get_name_score(query)
        print(str(score))


if __name__ == "__main__":
    main()
