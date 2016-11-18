/*
Solution to the "ChessboardGame" challenge by HackerRank:
https://www.hackerrank.com/challenges/a-chessboard-game-1
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int x, y;
    std::cin >> x >> y;

    // The coin position can always be reduced
    // to the following 4x4 final board:
    // - | 1 2 3 4
    // - + - - - -
    // 1 | L L W W
    // 2 | L L W W
    // 3 | W W W W
    // 4 | W W W W

    x %= 4;
    y %= 4;

    bool losing = ((1 == x) || (2 == x)) && ((1 == y) || (2 == y));
    std::cout << (losing ? "Second" : "First") << std::endl;
  }

  return 0;
}
