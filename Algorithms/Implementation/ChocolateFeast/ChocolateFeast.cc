/*
Solution to the "Chocolate Feast" challenge by HackerRank:
https://www.hackerrank.com/challenges/chocolate-feast
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;
  for(int t = 0; t < T; ++t)
  {
    int N, C, M, newChocolates, wrappers, totalChocolates;
    std::cin >> N >> C >> M;
    totalChocolates = 0;
    wrappers = 0;

    // Little Bob buys all the chocolate he may afford:
    newChocolates = N / C;

    while(newChocolates > 0)
    {
      totalChocolates += newChocolates;
      wrappers += newChocolates;

      // and then he exchanges each M wrappers for a new chocolate bar.
      newChocolates = wrappers / M;
      wrappers -= newChocolates * M;
    }

    std::cout << totalChocolates << std::endl;
  }

  return 0;
}
