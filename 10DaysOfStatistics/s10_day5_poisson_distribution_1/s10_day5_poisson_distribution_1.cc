/*
Solution to the "s10_day5_poisson_distribution_1" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-poisson-distribution-1
Written on 28-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <cmath>
#include <iomanip>


// Returns a factorial (n!) of a number passed as a parameter.
unsigned long long int factorial(int n)
{
  unsigned long long int ans = 1ULL;
  for(unsigned long long int i = 2ULL; i <= n; ++i)
  {
    ans *= i;
  }

  return ans;
}


// Returns the expected number of events in k space for Poisson variable:
double poisson(int k, double lambda)
{
  double numerator = static_cast<double>
      (std::pow(lambda, k) * std::exp(-lambda));
  double denominator = static_cast<double>(factorial(k));

  return (numerator / denominator);
}


int main(int argc, char **argv)
{
  int k;
  double lambda;

  // Reads in the data:
  std::cin >> lambda >> k;

  // Calculates and prints out the answer:
  double ans = poisson(k, lambda);
  std::cout << std::setprecision(3) << std::fixed << ans << std::endl;

  return 0;
}
