#!/usr/bin/env python

"""
Problem statement: 
Evaluate the sum of all the amicable numbers under N. N <= 100000.
"""

"""
NOTE: (very) inefficient. It's rainy today and the air pressure is so low,
   just same as the quality of the following code:
"""

""" Amicable pairs under 100000 (100k) are: """
amicable = [220, 284, 1184, 1210, 2620, 2924, 5020, 5564, 6232, 6368, 10744,
            10856, 12285, 14595, 17296, 18416, 63020, 66928, 66992, 67095,
            69615, 71145, 76084, 79750, 87633, 88730]


def get_proper_divisors(n):
    ans = []
    for k in range(1, n):
        if n % k is 0:
            ans.append(k)
    return ans


def sum_of_proper_divisors(n):
    return sum(get_proper_divisors(n))


def calculate_amicable_numbers_upto(limit):
    amicable = []
    for k in range(4, limit + 1):
        if k not in amicable:
            k_sum = sum_of_proper_divisors(k)
            k_sum_sum = sum_of_proper_divisors(k_sum)
            if (k_sum_sum == k) and (k_sum != k):
                amicable.append(k)
                amicable.append(k_sum)
        # if k % (limit // 100) == 0:
            # print ("Calculating: %d%% done." % (100 * k // limit,))
    return amicable

def main():
    # # Generates the list of amicable numbers - which will be fed to sort tool:
    # ami = calculate_amicable_numbers_upto(100005)
    # print("\n".join(str(a) for a in ami))

    for t in range(int(input())):
        N = int(input())
        lesser = [ami for ami in amicable if ami < N]
        print(str(sum(lesser)))



if __name__ == "__main__":
    main()
