/*
Solution to the "CompareTheTriplets" challenge by HackerRank:
https://www.hackerrank.com/challenges/compare-the-triplets
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
    int a0;
    int a1;
    int a2;
    std::cin >> a0 >> a1 >> a2;
    int b0;
    int b1;
    int b2;
    std::cin >> b0 >> b1 >> b2;

    int a = 0, b = 0;
    if(a0 > b0) {
        ++a;
    } else if(b0 > a0) {
        ++b;
    }
    if(a1 > b1) {
        ++a;
    } else if(b1 > a1) {
        ++b;
    }
    if(a2 > b2) {
        ++a;
    } else if(b2 > a2) {
        ++b;
    }

    std::cout << a << " " << b << std::endl;
    return 0;
}
