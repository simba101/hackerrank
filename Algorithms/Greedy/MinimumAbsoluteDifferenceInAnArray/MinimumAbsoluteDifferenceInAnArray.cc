/*
Solution to the "MinimumAbsoluteDifferenceInAnArray" challenge by HackerRank:
https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array
Written on 15-03-2017 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main(int argc, char **argv)
{
  int N;
  std::cin >> N;

  std::vector< int > vec(N);
  for (int n = 0; n < N; ++n)
  {
    std::cin >> vec[n];
  }

  std::sort(vec.begin(), vec.end());

  int mindiff = std::abs(vec[0] - vec[1]);

  for (int k = 2; k < N; ++k)
  {
    int diff = std::abs(vec[k - 1] - vec[k]);
    if (diff < mindiff)
    {
      mindiff = diff;
    }
  }

  std::cout << mindiff << std::endl;

  return 0;
}
