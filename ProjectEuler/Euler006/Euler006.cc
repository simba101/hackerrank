/*
Solution to the "Euler006" challenge by HackerRank:
https://www.hackerrank.com/contests/projecteuler/challenges/euler006
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

    int sum = (N * (N + 1)) / 2ULL;
    unsigned long long int sum_of_squares = 0;
    for(int i = 1; i <= N; ++i)
    {
      sum_of_squares += static_cast<unsigned long long int>(i * i);
    }

    unsigned long long int sum_ull =
        static_cast<unsigned long long int>(sum);
    unsigned long long int square_of_sum = sum_ull * sum_ull;

    if(square_of_sum > sum_of_squares)
    {
      std::cout << square_of_sum - sum_of_squares << std::endl;
    }
    else
    {
      std::cout << sum_of_squares - square_of_sum << std::endl;
    }
  }

  return 0;
}
