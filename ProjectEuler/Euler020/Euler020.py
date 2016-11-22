#!/usr/bin/env python

factorials = [0] * 1001   # From 0 to 1000 inclusively.

def precompute_factorials():
    factorials[0] = 1
    for i in range(1, 1001): # From 1 to 1000 inclusively.
        factorials[i] = factorials[i - 1] * i

def get_digits_sum(number):
    digits_sum = 0
    strnum = str(number)
    for i in range(len(strnum)):
        digits_sum += int(strnum[i])

    return digits_sum

def main():
    precompute_factorials()

    for t in range(int(input())):
        N = int(input())
        print(get_digits_sum(factorials[N]))

if __name__ == "__main__":
    main()
