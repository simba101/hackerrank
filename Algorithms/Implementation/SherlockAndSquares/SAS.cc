/*
Solution to "Sherlock and the Squares" challenge by HackerRank.
https://www.hackerrank.com/challenges/sherlock-and-squares
by simba (szczerbiakadam@gmail.com)
*/

#include <iostream>
#include <cmath>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int a, b;
    std::cin >> a >> b;

    int ia = std::ceil(std::sqrt(a));
    int ib = std::floor(std::sqrt(b));

    std::cout << ib - ia + 1 << std::endl;
  }

  return 0;
}
