/*
Solution to the "s10_day6_central_limit_theorem_3" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-the-central-limit-theorem-3
Written on 30-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <cmath>
#include <iomanip>


const double epsilon = 1e-4; // That's a really large epsilon :)

int main(int argc, char **argv)
{
  // Gathers the data:
  double sampleSize, totalMean, totalSigma, interval, zscore;
  std::cin >> sampleSize >> totalMean >> totalSigma >> interval >> zscore;

  // Calculates the parameters of the distribution inside the samples group:
  double sampleMean = totalMean;
  double sampleSigma = totalSigma / std::sqrt(sampleSize);

  double A = sampleMean - (zscore * sampleSigma);
  double B = sampleMean + (zscore * sampleSigma);

  std::cout << std::setprecision(2) << std::fixed
            << A << std::endl << B << std::endl;

  return 0;
}
