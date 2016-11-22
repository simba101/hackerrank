#!/usr/bin/env python

def main():
    count_str = input()
    count = int(count_str)

    number_str = ""
    total = 0
    for line in range(count):
        number_str = input()
        number = int(number_str)
        total += number

    total_str = str(total)

    print(total_str[:10])


if __name__ == "__main__":
    main()
