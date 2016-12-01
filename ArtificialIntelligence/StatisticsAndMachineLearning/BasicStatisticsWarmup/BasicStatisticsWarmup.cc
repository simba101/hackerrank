/*
Solution to the "BasicStatisticsWarmup" challenge by HackerRank:
https://www.hackerrank.com/challenges/stat-warmup
Written on 01-12-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>


// Returns the mean value of a vector of integers.
double mean(std::vector<int> const &v)
{
  int sum = 0;
  for(int i = 0; i < v.size(); ++i)
  {
    sum += v[i];
  }

  return (static_cast<double>(sum) / v.size());
}

// Returns the median of a vector of integers.
// Attention: produces valid output only for already sorted vectors.
double median(std::vector<int> const &v)
{
  // returns the median:
  return (v[(v.size() - 1) / 2] + v[v.size() / 2]) / 2.0;
}

// Returns the numerically smallest mode.
// Attention: produces valid output only for already sorted vectors.
int mode(std::vector<int> const &v)
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

// Returns the standard deviation of the vector's values.
double std_dev(std::vector<int> const &v)
{
  // Calculates the mean:
  double _mean = mean(v);

  // Calculates the sum of squared error:
  double sqdist = 0.0;
  for(int i = 0; i < v.size(); ++i)
  {
    sqdist += ((v[i] - _mean) * (v[i] - _mean));
  }

  // Returns the standard deviation:
  return std::sqrt(sqdist / v.size());
}

int main(int argc, char **argv)
{
  // Reads the first line of input - the numbers' count.
  int N;
  std::cin >> N;

  // Reads N numbers into the vector:
  std::vector<int> data(N);
  for(int i = 0; i < N; ++i)
  {
    std::cin >> data[i];
  }

  // Sorts the vector in a nondescending order:
  std::sort(data.begin(), data.end());

  double vmean = mean(data);
  double vmedian = median(data);
  double vmode = mode(data);
  double vsigma = std_dev(data);

  // Lower and Upper boundary of confidence interval:
  double confidence = 1.96 * (vsigma / std::sqrt(data.size()));

  double lower = vmean - confidence;
  double upper = vmean + confidence;

  // Prints out the answers, taking care to print them
  // EXACTLY in the format this project requires
  std::cout << std::setprecision(1) << std::fixed
      << vmean << std::endl
      << vmedian << std::endl
      << std::setprecision(0) << vmode << std::endl
      << std::setprecision(1) << vsigma << std::endl
      << lower << " " << upper << std::endl;

  return 0;
}
