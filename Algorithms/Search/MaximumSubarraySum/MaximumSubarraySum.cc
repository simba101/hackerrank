/*
Solution to the "MaximumSubarraySum" challenge by HackerRank:
https://www.hackerrank.com/challenges/maximum-subarray-sum
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for (int t = 0; t < T; ++t)
  {
    int N;
    unsigned long long M;
    std::pair<unsigned long long int, int> entry;
    std::cin >> N >> M;

    std::vector<std::pair<unsigned long long int, int>> list;
    list.reserve(N);
    for (int n = 0; n < N; ++n)
    {
      std::cin >> entry.first;
      entry.second = n + 1;
      list.push_back(entry);
    }

    list.at(0).first %= M;
    unsigned long long int maxX = list.at(0).first;
    for (int n = 1; n < N; ++n)
    {
      list.at(n).first =
          ((list.at(n).first % M) + (list.at(n - 1).first % M)) % M;
      if (list.at(n).first > maxX)
      {
        maxX = list.at(n).first;
      }
    }

    std::sort(list.begin(), list.end());

    unsigned long long minX = ULONG_MAX;
    for (int n = 0; n < (N - 1); ++n)
    {
      if (list.at(n).second > list.at(n + 1).second)
      {
        if (list.at(n + 1).first - list.at(n).first < minX)
        {
          minX = list.at(n + 1).first - list.at(n).first;
        }
      }
    }

    std::cout << std::max(maxX, M - minX) << std::endl;
  }

  return 0;
}

