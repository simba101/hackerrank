/*
Solution to the "s10_day1_standard_deviation" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-standard-deviation
Written on 28-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <vector>
#include <cmath> // needed for std::sqrt() calls
#include <iomanip>


int main(int argc, char **argv)
{
  // Gathers the input data:
  int N;
  std::vector<int> data;
  int sum = 0;

  std::cin >> N;
  data.resize(N);
  for(int i = 0; i < N; ++i)
  {
    std::cin >> data[i];
    sum += data[i];
  }

  // Calculates the mean:
  double mean = static_cast<double>(sum) / N;

  // Calculates the sum of squared distances (squared error):
  double sqdist = 0.0;
  for(int i = 0; i < N; ++i)
  {
    sqdist += ((data[i] - mean) * (data[i] - mean));
  }

  // Finally calculates the standard deviation:
  double std_dev = std::sqrt(sqdist / N);

  // And prints out the answer in the requested format:
  std::cout << std::setprecision(1) << std::fixed << std_dev << std::endl;

  return 0;
}
