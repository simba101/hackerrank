/*
Solution to the "Euler001" challenge by HackerRank:
https://www.hackerrank.com/contests/projecteuler/challenges/euler001/
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;
  for(int t = 0; t < T; ++t)
  {
    int N;
    std::cin >> N;

    // Finds the sum of the multiples of three < N:
    unsigned long long h3 = (N - 1) / 3;
    unsigned long long sum3 = (3ULL * h3 * (h3 + 1ULL)) / 2ULL;

    // Finds the sum of the multiples of five < N:
    unsigned long long h5 = (N - 1) / 5;
    unsigned long long sum5 = (5ULL * h5 * (h5 + 1ULL)) / 2ULL;

    // Finds the sum of the multiples of fifteen < N:
    unsigned long long h15 = (N - 1) / 15;
    unsigned long long sum15 = (15ULL * h15 * (h15 + 1ULL)) / 2ULL;

    unsigned long long total = sum5 - sum15 + sum3;
    //std::cout << sum3 << " "<< sum5 << " "<< sum15 << " " << total << std::endl;
    std::cout << total << std::endl;
  }
  return 0;
}
