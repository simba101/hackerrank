/*
Solution to the "Pairs" challenge by HackerRank:
https://www.hackerrank.com/challenges/pairs
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
  int N, K;
  std::vector<int> list;
  int first = 1, second = 0, pairs = 0, diff;

  std::cin >> N >> K;

  list.resize(N);
  for (int n = 0; n < N; ++n)
  {
    std::cin >> list[n];
  }
  std::sort(list.begin(), list.end());

  while (first < N)
  {
    diff = list[first] - list[second];
    // std::cout << "first: " << first << ", second: " << second
    //           << " diff: " << diff << std::endl;
    if (diff > K)
    {
      ++second;
    }
    else
    {
      ++first;
      if (diff == K)
      {
        ++pairs;
      }
    }
  }

  std::cout << pairs << std::endl;

  return 0;
}
