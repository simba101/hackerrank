/*
Solution to the "s10_day4_binomial_distribution_1" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-binomial-distribution-1
Written on 28-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <cmath>
#include <iomanip>


// Returns a factorial (n!) of a number provided as a parameter.
unsigned long long int factorial(unsigned int n)
{
  unsigned long long int result = 1ULL;
  for(unsigned long long int i = 2; i <= n; ++i)
  {
    result *= i;
  }

  return result;
}

// Returns the value of (n!) / ( (k!) * ((n - k)!)).
unsigned long long int n_choose_k(unsigned int n, unsigned int k)
{
  return (factorial(n) / (factorial(k) * factorial(n - k)));
}

double get_binomial_probability(unsigned int n, unsigned int k,
    double success_prob)
{
  return (static_cast<double>(n_choose_k(n, k)) * (std::pow(success_prob, k)) *
      (std::pow(1 - success_prob, n - k)));
}


int main(int argc, char **argv)
{
  double maleRatio, femaleRatio;
  std::cin >> maleRatio >> femaleRatio;

  double maleOdds = maleRatio / (maleRatio + femaleRatio);
  double femaleOdds = femaleRatio / (maleRatio + femaleRatio);

  // calculates the % of the families having exactly 3 male children out of 6:
  double prb3 = get_binomial_probability(6, 3, maleOdds);

  // calculates the % of the families having exactly 4 male children out of 6:
  double prb4 = get_binomial_probability(6, 4, maleOdds);

  // calculates the % of the families having exactly 5 male children out of 6:
  double prb5 = get_binomial_probability(6, 5, maleOdds);

  // calculates the % of the families having exactly 6 male children out of 6:
  double prb6 = get_binomial_probability(6, 6, maleOdds);

  // calculates the answer to this problem:
  // what % of all families of 6 children have at least 3 male children?
  double ans = prb3 + prb4 + prb5 + prb6;

  std::cout << std::setprecision(3) << std::fixed << ans << std::endl;
}
