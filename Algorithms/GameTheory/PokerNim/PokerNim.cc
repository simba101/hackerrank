/*
Solution to the "PokerNim" challenge by HackerRank:
https://www.hackerrank.com/challenges/poker-nim-1
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N, K, xored, pile;
    std::cin >> N >> K;
    xored = 0;
    for(int n = 0; n < N; ++n)
    {
      std::cin >> pile;
      xored ^= pile;
    }

    std::cout << (xored == 0 ? "Second" : "First") << std::endl;
  }

  return 0;
}
