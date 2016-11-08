#!/usr/bin/env python3

"""
Solution to the "FibonacciModified" challenge by HackerRank:
https://www.hackerrank.com/challenges/fibonacci-modified
by simba (szczerbiakadam@gmail.com).
"""

lst = list(map(int, input().split()))
t1 = lst[0]
t2 = lst[1]
N = lst[2]

pre = t1
last = t2
curr = last * last + pre

n = 3

while(n != N):
    pre = last
    last = curr
    curr = last * last + pre
    n += 1

print("%d" % curr)
