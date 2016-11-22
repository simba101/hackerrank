/*
Solution to the "Euler010" challenge by HackerRank:
https://www.hackerrank.com/contests/projecteuler/challenges/euler010
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> primes;
const int N_LIMIT = 1001000;


void populatePrimesList(void)
{
  primes.clear();

  // due to the limitations of c++ language (no way to initialize the array
  // with true values) let's treat 'false' as "is-prime" and 'true' as "isn't".
  bool sieve[N_LIMIT + 1] = {false};

  // filters out even values:
  for(int k = 4; k <= N_LIMIT; k += 2)
  {
    sieve[k] = true;
  }
  for(int k = 3; k <= std::sqrt(N_LIMIT); k += 2)
  {
    if(!sieve[k])
    {
      for(int c = k * 2; c <= N_LIMIT; c += k)
      {
        sieve[c] = true;
      }
    }
  }

  // adds primes to the list:
  for(int p = 2; p <= N_LIMIT; ++p)
  {
    if(!sieve[p])
    {
      primes.push_back(p);
    }
  }
}

int main(int argc, char **argv)
{
  populatePrimesList();

  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N;
    std::cin >> N;

    volatile unsigned long long int sum = 0;
    int p = primes[0];
    int pos = 0;
    while(p <= N)
    {
      sum += static_cast<unsigned long long int>(p);
      pos += 1;
      p = primes[pos];
    }
    std::cout << sum << std::endl;
  }

  return 0;
}
