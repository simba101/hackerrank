#!/usr/bin/env python

smallNames = ["-", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]

decimalNames = ["-", "-", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
        "Eighty", "Ninety"]


"""Stringifies a triplet. A _triplet_ is an integer number greater than 0
   and lesser than 1000, in effect having at most three decimal digits.
   Returns a string containing English representation
   of the number provided as a parameter."""
def stringify_triplet(num):
    num = int(num)
    ans = [];
    hundreds = num // 100
    num -= (100 * hundreds)
    if hundreds > 0:
        ans.append(smallNames[hundreds])
        ans.append("Hundred")

    if(num > 0):
        if(num < 20):
            ans.append(smallNames[num])
        else:
            decimals = num // 10
            ans.append(decimalNames[decimals])
            num -= (10 * decimals)
            if(num > 0):
                ans.append(smallNames[num])
    return " ".join(ans)


"""Stringifies a natural number (0 < N <= 1e15 - 1). Returns a string containing
   English representation of a number."""
def stringify(num):
    strnum = str(num)
    units = strnum[-3:]
    thousands = strnum[-6:-3]
    millions = strnum[-9:-6]
    billions = strnum[-12:-9]
    trillions = strnum[-15:-12]

    iunits = int(units)
    ithousands = (int(thousands) if len(thousands) > 0 else 0)
    imillions = (int(millions) if len(millions) > 0 else 0)
    ibillions = (int(billions) if len(billions) > 0 else 0)
    itrillions = (int(trillions) if len(trillions) > 0 else 0)

    ans = [];
    if itrillions > 0:
        ans.append(stringify_triplet(trillions) + " Trillion")
    if ibillions > 0:
        ans.append(stringify_triplet(billions) + " Billion")
    if imillions > 0:
        ans.append(stringify_triplet(millions) + " Million")
    if ithousands > 0:
        ans.append(stringify_triplet(thousands) + " Thousand")
    if iunits > 0:
        ans.append(stringify_triplet(iunits))

    return " ".join(ans)



for t in range(int(input())):
    num = input()
    if num is 0:
        print("Zero")
    else:
        print(stringify(num))
