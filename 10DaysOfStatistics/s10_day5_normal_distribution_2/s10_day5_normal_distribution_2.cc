/*
Solution to the "s10_day5_normal_distribution_2" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-normal-distribution-2
Written on 29-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <cmath>      // needed for the erf() method.
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
  // Mean and standard deviation of a normal distribution,
  // Then queries A and B follow.
  double mean, sigma, A, B;
  std::cin >> mean >> sigma >> A >> B;

  // Calculates the answers to the queries.
  // Queries ask to find the percentage of students that...
  // First query: ...scored higher that A:
  double ans1 = 100.0 * (1.0 - normal(A, mean, sigma));

  // Second query: ...passed the test by scoring higher than B:
  double ans2 = 100.0 * (1.0 - normal(B, mean, sigma));

  // Third query: ...failed the test by scoring less than B:
  // Note that ans2 + ans3 = 100.0, so alternatively ans3 is 100.0 - ans2.
  double ans3 = 100.0 * normal(B, mean, sigma);

  // Prints the answers to the standard output:
  std::cout << std::setprecision(2) << std::fixed
            << ans1 << std::endl << ans2 << std::endl << ans3 << std::endl;

  return 0;
}
