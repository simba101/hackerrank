/*
Solution to the "s10_day4_geometric_distribution_2" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-geometric-distribution-2
Written on 28-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <iomanip>
#include <cmath>


/**
 * A machine manufactures a product, but there is a probability of p/q that
 * it will be broken. What is the probability that a broken product
 * will be found in a batch of N products?
 */

int main(int argc, char **argv)
{
  int p, q, N;
  std::cin >> p >> q >> N;
  double probability_of_failure = static_cast<double>(p) / q;
  double probability_of_success = 1 - probability_of_failure;

  // The probability that there will be at least one faulty product in a batch
  // of N samples is exactly:
  //   1 - [the probability that there are no faulty products in a batch].

  // Calculates and prints the answer in a requested format:
  double ans = 1 - std::pow(probability_of_success, N);
  std::cout << std::setprecision(3) << std::fixed << ans << std::endl;

  return 0;
}
