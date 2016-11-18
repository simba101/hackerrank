/*
Solution to the "NimGame1" challenge by HackerRank:
https://www.hackerrank.com/challenges/nim-game-1
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
    std::cin >> N;

    int pile;
    int xorpile = 0;
    for(int n = 0; n < N; ++n)
    {
      std::cin >> pile;
      xorpile ^= pile;
    }

    std::cout << (xorpile == 0 ? "Second" : "First") << std::endl;
  }

  return 0;
}
