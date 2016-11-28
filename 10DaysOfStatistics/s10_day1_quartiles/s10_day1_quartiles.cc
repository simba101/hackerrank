/*
Solution to the "s10_day1_quartiles" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-quartiles
Written on 25-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <vector>
#include <algorithm>

// Returns the median of a SORTED vector of int values.
double get_median(std::vector<int> const &v)
{
  return ((v[(v.size() - 1) / 2] + v[v.size() / 2]) / 2.0);
}

// The tests require to provide answers rounded down to the int values.
// Which seems wrong, quartiles are quite often fractional.
// Anyway, double values were used for correctness sake.
int main(int argc, char **argv)
{
  // Reads in the array's size and contents:
  int N;
  std::vector<int> data;
  std::cin >> N;
  data.resize(N);
  for (int n = 0; n < N; ++n)
  {
    std::cin >> data[n];
  }

  std::sort(data.begin(), data.end());

  // The median is a 2nd quartile as well:
  double median = get_median(data);

  // Prepares the vectors of lower and upper parts of the array:
  std::vector<int> lower, upper;
  lower.resize(data.size() / 2);
  upper.resize(data.size() / 2);

  // Fills in the data for lower and upper halves of the array, median excluded:
  int offset = (data.size() + 1) / 2;
  for(int i = 0; i < data.size() / 2; ++i)
  {
    lower[i] = data[i];
    upper[i] = data[i + offset];
  }

  // Calculates the 1st and 3rd quartiles as medians of lower/upper vectors:
  double q1 = get_median(lower);
  double q3 = get_median(upper);

  // Prints out the answer:
  std::cout << q1 << std::endl << median << std::endl << q3 << std::endl;

  return 0;
}
