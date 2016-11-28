/*
Solution to the "s10_day1_interquartile_range" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-interquartile-range
Written on 28-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>


// Returns the median of a SORTED vector of int values.
double get_median(std::vector<int> const &v)
{
  return ((v[(v.size() - 1) / 2] + v[v.size() / 2]) / 2.0);
}

int main(int argc, char **argv)
{
  // loads the data:
  int N;
  std::vector<int> X, F;
  std::vector<int> data;

  // Reads the size of the values/frequencies arrays and resizes the arrays:
  std::cin >> N;
  X.resize(N);
  F.resize(N);

  // Reads in the content of values (X) and frequencies (F) arrays:
  for(int n = 0; n < N; ++n)
  {
    std::cin >> X[n];
  }
  for(int n = 0; n < N; ++n)
  {
    std::cin >> F[n];
  }

  // Generates the data array:
  for(int item = 0; item < N; ++item)
  {
    for(int freq = 0; freq < F[item]; ++freq)
    {
      data.push_back(X[item]);
    }
  }

  // Sorts the data array in the nondescending order:
  std::sort(data.begin(), data.end());

  // Prepares the vectors holding the lower and upper parts of the array:
  std::vector<int> lower, upper;
  lower.resize(data.size() / 2);
  upper.resize(data.size() / 2);

  // Fills in the lower and upper halves of the array, median excluded:
  int offset = (data.size() + 1) / 2;
  for(int i = 0; i < data.size() / 2; ++i)
  {
    lower[i] = data[i];
    upper[i] = data[i + offset];
  }

  // Calculates the 1st and 3rd quartiles:
  double q1 = get_median(lower);
  double q3 = get_median(upper);

  // Prints out the answer, which is the difference
  // between the 3rd and the 1st quartile:
  std::cout << std::setprecision(1) << std::fixed << (q3 - q1) << std::endl;

  return 0;
}
