/*
Solution to the "s10_day0_basic_statistics" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-basic-statistics
Written on 25-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <iomanip> // for setting the printed floating-point numbers' precision
#include <vector>
#include <algorithm> // for sorting the vector

// Constraints:
// 10 <= N <= 2500
// 0 < x_i <= 10e5, where x_i is the i-th element of the array.

// Calculates the mean.
double calculate_mean(std::vector<int> const &v)
{
  // int should suffice for this challenge (see the constraints).
  int sum = 0;
  for(int i = 0; i < v.size(); ++i)
  {
    sum += v[i];
  }
  return (static_cast<double>(sum) / v.size());
}

// Calculates the median.
// Produces valid output only for already sorted vectors.
double calculate_median(std::vector<int> const &v)
{
  // With the use of integer division, this will produce a valid output
  // for both even- and odd-sized arrays:
  double A = v[(v.size() - 1) / 2];
  double B = v[v.size() / 2];
  return ((A + B) / 2.0);
}

// Calculates the mode.
// Produces valid output only for already sorted vectors.
int calculate_mode(std::vector<int> const &v)
{
  int mode = -1;
  int mode_frequency = 0;
  int current_frequency = 1;

  for(int i = 1; i < v.size(); ++i)
  {
    if(v[i] != v[i - 1])
    {
      if(current_frequency > mode_frequency)
      {
        mode = v[i - 1];
        mode_frequency = current_frequency;
      }
      current_frequency = 1;
    }
    else
    {
      current_frequency += 1;
    }
  }

  // Need to perform one last check for the last set of values:
  if(current_frequency > mode_frequency)
  {
    mode = v[v.size() - 1];
  }

  return mode;
}


int main(int argc, char **argv)
{
  // Gets the size of an array of integers:
  int N;
  std::cin >> N;

  // Holds the array of integers:
  std::vector<int> numbers;
  numbers.resize(N);
  for(int n = 0; n < N; ++n)
  {
    std::cin >> numbers[n];
  }

  // Sorts the array in order to calculate the median and the mode:
  std::sort(numbers.begin(), numbers.end());

  // The values that need to be computed:
  double mean = calculate_mean(numbers);
  double median = calculate_median(numbers);
  int mode = calculate_mode(numbers);

  // Outputs the answers - mean, median and mode; each on its own line:
  std::cout << std::setprecision(1) << std::fixed;
  std::cout << mean << std::endl << median << std::endl << mode << std::endl;

  return 0;
}
