/*
Solution to a "Service Lane" challenge by HackerRank
https://www.hackerrank.com/challenges/service-lane
by simba (szczerbiakadam@gmail.com)
*/

#include <iostream>

int main(int argc, char **argv)
{
  int N, T;
  // constraints: 2 <= N <= 100000, 1 <= T <= 1000
  std::cin >> N >> T;

  int laneLength[100000];

  // reads the lane width map from stdin:
  for(int n = 0; n < N; ++n)
  {
    std::cin >> laneLength[n];
  }

  // conducts the tests:
  for(int t = 0; t < T; ++t)
  {
    int startLane, endLane;
    std::cin >> startLane >> endLane;

    int maxWidth = 3;

    for(int l = startLane; l <= endLane; ++l)
    {
      if(laneLength[l] < maxWidth)
      {
        maxWidth = laneLength[l];
      }
    }
    std::cout << maxWidth << std::endl;
  }

  return 0;
}
