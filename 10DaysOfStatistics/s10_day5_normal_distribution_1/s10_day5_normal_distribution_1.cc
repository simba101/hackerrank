/*
Solution to the "s10_day5_normal_distribution_1" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-normal-distribution-1
Written on 29-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <cmath>       // for the erf() method
#include <iomanip>


// Calculates the probability of a variable from the normal distribution
// of mean=mean and standard deviation=sigma being less than value.
double normal(double value, double mean, double sigma)
{
  return 0.5 * (1.0 + std::erf( (value - mean) / (sigma * std::sqrt(2.0)) ));
}

int main(int argc, char **argv)
{
  // Reads the following information from the standard input:
  // Mean, standard deviation for the variable X,
  // A - First query (find the probability that X is less than A)
  // B, C - Second query (find the prb. that X is between B and C)
  double mean, sigma, A, B, C;
  std::cin >> mean >> sigma >> A >> B >> C;

  // Calculates the answers to the two queries:
  double ans1 = normal(A, mean, sigma);
  double ans2 = normal(C, mean, sigma) - normal(B, mean, sigma);

  std::cout << std::setprecision(3) << std::fixed
            << ans1 << std::endl << ans2 << std::endl;
  return 0;
}
