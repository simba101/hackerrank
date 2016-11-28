/*
Solution to the "s10_day4_geometric_distribution_1" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-geometric-distribution-1
Written on 28-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <iomanip>
#include <cmath>


// Calculates the probability that the event occuring with probability of p
// every time occurs exactly at the n-th trial.
double geometric(int n, double p)
{
  // This requires a "stream" of n-1 consecutive "failures" and then
  // one "success":
  return std::pow(1 - p, n - 1) * p;
}

int main(int argc, char **argv)
{
  /**
   * The problem statement is written poorly.
   * This code answers the following question:
   *
   * Given the probability for a machine to produce a defective item,
   * print the probability that the n-th produced item
   * will be the first defective one.
   */

  // Reads in the probability of failure in form of numerator and denominator:
  int numerator, denominator;
  std::cin >> numerator >> denominator;
  double prb_of_defect = static_cast<double>(numerator) / denominator;

  // Reads in the position of the first defective item:
  int position;
  std::cin >> position;

  // Calculates the probability of that outcome:
  double ans = geometric(position, prb_of_defect);

  // Prints out the answer:
  std::cout << std::setprecision(3) << std::fixed << ans << std::endl;

  return 0;
}
