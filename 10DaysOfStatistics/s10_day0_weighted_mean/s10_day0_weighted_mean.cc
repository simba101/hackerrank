/*
Solution to the "s10_day0_weighted_mean" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-weighted-mean
Written on 25-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <iomanip> // for setting the precision of printed floating-point values
#include <vector>


// Congregates together the value and its weight.
struct data
{
  int value;
  int weight;
};

int main(int argc, char **argv)
{
  int N;
  std::cin >> N;

  std::vector<data> input;
  input.resize(N);

  // Gathers the data:
  for(int n = 0; n < N; ++n)
  {
    std::cin >> input[n].value;
  }
  for(int n = 0; n < N; ++n)
  {
    std::cin >> input[n].weight;
  }

  int sumOfWeights = 0;
  int sumOfWeightedElements = 0;

  for(int n = 0; n < N; ++n)
  {
    sumOfWeights += input[n].weight;
    sumOfWeightedElements += (input[n].value * input[n].weight);
  }

  double weightedMean =
          static_cast<double>(sumOfWeightedElements) / sumOfWeights;

  std::cout << std::setprecision(1) << std::fixed << weightedMean << std::endl;

  return 0;
}
