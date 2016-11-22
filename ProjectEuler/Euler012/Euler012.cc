/*
Solution to the "Euler012" challenge by HackerRank:
https://www.hackerrank.com/contests/projecteuler/challenges/euler012
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int answers[1000 + 1];

int divisors(int n)
{
  if(n == 1)
  {
    return 1;
  }

  int factors = 0;
  for(int i = 1; i <= std::sqrt(n); ++i)
  {
    if(0 == (n % i))
    {
      factors += 2;
    }
    if(n == i * i)
    {
      factors -= 1;
    }
  }

  return factors;
}

void get_answers()
{
  answers[0] = 1;
  answers[1] = 3;
  answers[2] = answers[3] = 6;
  answers[4] = answers[5] = 28;

  for(int i = 6; i <= 1000; ++i)
  {
    answers[i] = -1;
  }

  int kappa = 7; // next Tn: 7*8 / 2 = 36.
  while(-1 == answers[1000])
  {
    int factor1, factor2;
    if(0 == kappa % 2)
    {
      factor1 = kappa / 2;
      factor2 = kappa + 1;
    }
    else
    {
      factor1 = (kappa + 1) / 2;
      factor2 = kappa;
    }

    int totalFactors = divisors(factor1) * divisors(factor2);

    int k = totalFactors - 1;
    // handles the case of overflowing the array:
    if(k > 1000)
    {
      k = 1000;
    }
    if(-1 == answers[k])
    {
      // calculates the value of a triangular number:
      int Tn = ((kappa + 1) * kappa) / 2;
      for(; -1 == answers[k]; --k)
      {
        answers[k] = Tn;
      }
    }

    kappa += 1;
  }
}

///////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
  get_answers();

  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N;
    std::cin >> N;
    std::cout << answers[N] << std::endl;
  }

  return 0;
}
