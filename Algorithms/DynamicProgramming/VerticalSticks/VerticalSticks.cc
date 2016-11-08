/*
Solution to the "VerticalSticks" challenge by HackerRank:
https://www.hackerrank.com/challenges/vertical-sticks
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;
  std::cout << std::setprecision(2) << std::fixed;

  for(int t = 0; t < T; ++t)
  {
    int N;
    std::cin >> N;
    std::vector<int> sticks;
    sticks.resize(N);
    for(int n = 0; n < N; ++n)
    {
      std::cin >> sticks[n];
    }

    std::vector<int> noOfGreaterThanOrEqualSticks;
    noOfGreaterThanOrEqualSticks.resize(N);

    for(int n = 0; n < N; ++n)
    {
      noOfGreaterThanOrEqualSticks[n] = 0;
      for(int k = 0; k < N; ++k)
      {
        if(sticks[k] >= sticks[n])
        {
          ++noOfGreaterThanOrEqualSticks[n];
        }
      }
    }

    double probability = 0.0;
    for(int k = 0; k < N; ++k)
    {
      double p = static_cast<double>(N + 1)
          / (noOfGreaterThanOrEqualSticks[k] + 1);
      probability += p;
    }

    std::cout << probability << std::endl;
  }

  return 0;
}
