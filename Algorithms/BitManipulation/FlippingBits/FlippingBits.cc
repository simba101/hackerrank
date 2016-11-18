/*
Solution to the "FlippingBits" challenge by HackerRank:
https://www.hackerrank.com/challenges/flipping-bits
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <climits>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    unsigned int input;
    std::cin >> input;

    input ^= UINT_MAX;

    std::cout << input << std::endl;
  }

  return 0;
}
