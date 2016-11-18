/*
Solution to the "NimbleGame" challenge by HackerRank:
https://www.hackerrank.com/challenges/nimble-game-1
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N;
    int coins, xored = 0;
    std::cin >> N;
    for(int n = 0; n < N; ++n)
    {
      std::cin >> coins;

      // If there is even number of coins, it trivially reduces to (0,0),
      // so only odd-numbered squares should be analyzed.
      if(1 == coins % 2)
      {
        xored ^= n;
      }
    }

    std::cout << (0 == xored ? "Second" : "First") << std::endl;
  }

  return 0;
}
