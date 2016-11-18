/*
Solution to the "MaximizingXor" challenge by HackerRank:
https://www.hackerrank.com/challenges/maximizing-xor
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int L, R;
  std::cin >> L >> R;

  int maxXor = 0;

  for(int l = L; l < R; ++l)
  {
    for(int r = l + 1; r <= R; ++r)
    {
      int x = l ^ r;
      maxXor >= x ?: maxXor = x;
    }
  }

  std::cout << maxXor << std::endl;

  return 0;
}
