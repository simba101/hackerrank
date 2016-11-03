#!/bin/python3
"""
Solution to the "ExtraLongFactorials" challenge by HackerRank:
https://www.hackerrank.com/challenges/extra-long-factorials
by simba (szczerbiakadam@gmail.com).
"""

import sys

n = int(input().strip())

factorial = 1
for i in range(n):
    factorial = factorial * (i + 1)

print(factorial)
