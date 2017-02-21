#!/usr/bin/env python3

import math

LIMIT = 5000 + 1 # digits in decimal representation
ARRAY_SIZE = 24000 # An oracle (python, namely) told me that 23932th fibonacci
                   # number exceeds 5000 digits in decimal notation :)

fibs = [0] * ARRAY_SIZE
fibs[1] = 1
fibs[2] = 1
n = 2
while (fibs[n] < 10 ** LIMIT):
    fibs[n + 1] = fibs[n - 1] + fibs[n]
    n += 1

digits = [0] * ARRAY_SIZE
for k in range(1, n+1):
    digits[k] = int(math.log10(fibs[k])) + 1

# What is the first term in the sequence that contains N digits?
answers = [0] * ARRAY_SIZE
answers[1] = 1 # 1st term of fib sequence has 1 digit length.
answered_so_far = 1
last_digits = 1
last_answer = 1
ans = 1
while (last_digits <= 5000):
    ans += 1
    digits_diff = digits[ans] - digits[last_answer]
    if(digits_diff > 0): # it will always be at most 1 digits difference!
        last_answer = ans
        last_digits = digits[ans]
        answers[last_digits] = ans

T = int(input())
for t in range(T):
    query = int(input())
    print(answers[query])
