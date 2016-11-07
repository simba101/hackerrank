/*
Solution to the "AngryChildren" challenge by HackerRank:
https://www.hackerrank.com/challenges/angry-children
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char **argv)
{
  int N, K, nextInt, minValPtr, minValDiff, nextValDiff;
  std::vector<int> list;

  // Reads the input from the stdin:
  std::cin >> N >> K;
  list.reserve(N);
  for(int n = 0; n < N; ++n)
  {
    std::cin >> nextInt;
    list.push_back(nextInt);
  }

  // Sorts the input list in ascending order:
  std::sort(list.begin(), list.end());

  // finds the minimum-list ptr:
  minValPtr = 0;
  minValDiff = list[K - 1] - list[0];
  for(int k = 1; k < N - K + 1; ++k)
  {
    nextValDiff = list[k + K - 1] - list[k];
    if(nextValDiff < minValDiff)
    {
      minValPtr = k;
      minValDiff = nextValDiff;
    }
  }

  std::cout << minValDiff << std::endl;
  return 0;
}
