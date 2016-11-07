/*
Solution to the "PriyankaAndToys" challenge by HackerRank:
https://www.hackerrank.com/challenges/priyanka-and-toys
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
  int N, toy;
  std::vector<int>toys;

  std::cin >> N;
  toys.reserve(N);

  for(int n = 0; n < N; ++n)
  {
    std::cin >> toy;
    toys.push_back(toy);
  }

  std::sort(toys.begin(), toys.end());

  int totalCost = 0;
  int previousWeight = -100;
  for(int i = 0; i < toys.size(); ++i)
  {
    if(toys[i] - previousWeight > 4)
    {
      totalCost += 1;
      previousWeight = toys[i];
    }
  }

  std::cout << totalCost << std::endl;

  return 0;
}
