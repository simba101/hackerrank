/*
Solution to the "s10_day6_central_limit_theorem_2" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-the-central-limit-theorem-2
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
  // Reads the available information from the stdin:
  double ticketsLeft, studentsCount, meanTickets, sigmaTickets;
  std::cin >> ticketsLeft >> studentsCount >> meanTickets >> sigmaTickets;

  // Calculates the probability that the total sold tickets are not exceeding
  // the value of ticketsLeft:
  double mean = studentsCount * meanTickets;
  double sigma = sigmaTickets * std::sqrt(studentsCount);
  double probability = normal(ticketsLeft, mean, sigma);

  // Prints the answer to the standard output:
  std::cout << std::setprecision(4) << std::fixed << probability << std::endl;

  return 0;
}
