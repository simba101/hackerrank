/*
Solution to the "GreedyFlorist" challenge by HackerRank:
https://www.hackerrank.com/challenges/greedy-florist
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
  int N, K, flower;
  std::vector<int> flowers;

  std::cin >> N >> K;
  flowers.reserve(N);
  for(int n = 0; n < N; ++n)
  {
    std::cin >> flower;
    flowers.push_back(flower);
  }

  std::sort(flowers.begin(), flowers.end(), std::greater<int>());

  int totalCost = 0;
  for(int f = 0; f < N; ++f)
  {
    totalCost += ((f / K) + 1) * flowers[f];
  }

  std::cout << totalCost << std::endl;

  return 0;
}
