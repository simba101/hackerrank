/*
Solution to the "GameOfStones" challenge by HackerRank:
https://www.hackerrank.com/challenges/game-of-stones-1
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
    std::cout << (N % 7 < 2 ? "Second" : "First") << std::endl;
  }

  return 0;
}
