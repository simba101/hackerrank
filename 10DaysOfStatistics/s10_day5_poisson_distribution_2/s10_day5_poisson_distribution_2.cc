/*
Solution to the "s10_day5_poisson_distribution_2" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-poisson-distribution-2
Written on 29-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <cmath>
#include <iomanip>


int main(int argc, char **argv)
{
  // The number of repairs that machines A and B need are Poisson variables
  // with respective means:
  double mean_repairs_A, mean_repairs_B;
  std::cin >> mean_repairs_A >> mean_repairs_B;

  double ansA = 160.0 + (40.0 * (mean_repairs_A * (mean_repairs_A + 1)));
  double ansB = 128.0 + (40.0 * (mean_repairs_B * (mean_repairs_B + 1)));

  std::cout << std::setprecision(3) << std::fixed
            << ansA << std::endl << ansB << std::endl;

  return 0;
}
