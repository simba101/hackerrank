#!/usr/bin/env python

for t in range(int(input())):
    exponent = int(input())
    num = 1 << exponent # 2^N
    digits = [int(digit) for digit in str(num)]
    print(sum(digits))
