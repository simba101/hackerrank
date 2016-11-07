/*
Solution to the "MarkAndToys" challenge by HackerRank:
https://www.hackerrank.com/challenges/mark-and-toys
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
  int N, K, toy;
  std::vector<int> toys;

  std::cin >> N >> K;
  for(int n = 0; n < N; ++n)
  {
    std::cin >> toy;
    toys.push_back(toy);
  }

  std::sort(toys.begin(), toys.end());

  toy = -1;
  int totalCost = 0;
  while(totalCost < K)
  {
    toy += 1;
    totalCost += toys[toy];
  }
  std::cout << toy << std::endl;
  return 0;
}
