/*
Solution to the "Euler005" challenge by HackerRank:
https://www.hackerrank.com/contests/projecteuler/challenges/euler005
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

const int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
int prime_factors[41][12] = {0};

void calculate_prime_factors()
{
  for(int n = 2; n <= 40; ++n)
  {
    int num = n;
    while(num > 1)
    {
      for(int k = 0; k < 12; ++k)
      {
        if(num % primes[k] == 0)
        {
          num /= primes[k];
          prime_factors[n][k] += 1;
        }
      }
    }
  }
}

int main(int argc, char **argv)
{
  calculate_prime_factors();

  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N;
    std::cin >> N;
    if(1 == N)
    {
      std::cout << "1" << std::endl;
    }
    else
    {
      int total_factors[12] = {0};
      for(int number = 2; number <= N; ++number)
      {
        for(int k = 0; k < 12; ++k)
        {
          if(prime_factors[number][k] > total_factors[k])
          {
            total_factors[k] = prime_factors[number][k];
          }
        }
      }

      int ans = 1;

      for(int k = 0; k < 12; ++k)
      {
        if(total_factors[k] > 0)
        {
          for(int i = 0; i < total_factors[k]; ++i)
          {
            ans *= primes[k];
          }
        }
      }

      std::cout << ans << std::endl;
    }
  }

  return 0;
}
