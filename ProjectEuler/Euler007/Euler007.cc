/*
Solution to the "Euler007" challenge by HackerRank:
https://www.hackerrank.com/contests/projecteuler/challenges/euler007
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <cmath>

// It is known in advance that the 10001th prime is < 105000
bool sieve[105000] = { false };
std::vector<int> primes;

void prepare_a_list_of_first_10000_primes()
{
  primes.clear();
  int limit = static_cast<int>(std::sqrt(105000));
  for(int p = 2; p <= limit; ++p)
  {
    int k = p + p;
    while(k < 105000)
    {
      sieve[k] = true;
      k += p;
    }
  }

  for(int p = 2; p <= 105000; ++p)
  {
    if(!sieve[p])
    {
      primes.push_back(p);
    }
  }
}

int main(int argc, char **argv)
{
  prepare_a_list_of_first_10000_primes();

  int T;
  std::cin >> T;

  int N;

  for(int t = 0; t < T; ++t)
  {
    std::cin >> N;
    std::cout << primes.at(N - 1) << std::endl;
  }

  return 0;
}
