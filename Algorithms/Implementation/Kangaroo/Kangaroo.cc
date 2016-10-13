/*
Solution to the "Kangaroo" challenge by HackerRank:
https://www.hackerrank.com/challenges/kangaroo
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int x1, v1, x2, v2;
  std::cin >> x1 >> v1 >> x2 >> v2;

  // It is guaranteed that the second kangaroo is further than the first.
  int position_diff = x2 - x1;

  // The speed of first kangaroo should be greater than the first one:
  int speed_diff = v1 - v2;

  bool willMeet = (speed_diff > 0 && (position_diff % speed_diff == 0));

  std::cout << (willMeet ? "YES" : "NO") << std::endl;

  return 0;
}
