/*
Solution to the "s10_day6_central_limit_theorem_1" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-the-central-limit-theorem-1
Written on 29-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <cmath>
#include <iomanip>

// Calculates the probability of a variable from the normal distribution
// of mean=mean and standard deviation=sigma being less than value.
double normal(double value, double mean, double sigma)
{
  return 0.5 * (1.0 + std::erf( (value - mean) / (sigma * std::sqrt(2.0)) ));
}

int main(int argc, char **argv)
{
  // Reads the data from the standard input:
  double maximumWeight, boxesCount, meanWeight, sigmaWeight;
  std::cin >> maximumWeight >> boxesCount >> meanWeight >> sigmaWeight;

  // When we add n normal random variables, the result is a random variable
  // whose mean' is n * mean and sigma' is sqrt(n) * sigma:
  double mean = boxesCount * meanWeight;
  double sigma = sigmaWeight * std::sqrt(boxesCount);

  // Will all the [boxesCount] boxes be lifted by the elevator?:
  double probability = normal(maximumWeight, mean, sigma);

  // Prints out the answer in a requested format:
  std::cout << std::setprecision(4) << std::fixed << probability << std::endl;

  return 0;
}
