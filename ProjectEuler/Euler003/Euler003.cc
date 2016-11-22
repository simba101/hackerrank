/*
Solution to the "Euler003" challenge by HackerRank:
https://www.hackerrank.com/contests/projecteuler/challenges/euler003
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <cmath>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    unsigned long long N;
    std::cin >> N;
    unsigned long long n = N;

    while(n % 2 == 0)
    {
      n = n / 2ULL;
    }

    if(1 == n)
    {
      std::cout << "2" << std::endl;
    }
    else
    {
      unsigned long long greatest_factor = 1ULL;
      unsigned long long limit = std::sqrt(N);
      unsigned long long factorer = 3ULL;
      while(factorer <= limit)
      {
        while(0 == n % factorer)
        {
          greatest_factor = factorer;
          n /= factorer;
        }

        factorer += 2ULL;
      }
      std::cout << (greatest_factor > n ? greatest_factor : n) << std::endl;
    }
  }

  return 0;
}
