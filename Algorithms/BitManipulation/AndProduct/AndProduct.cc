/*
Solution to the "AndProduct" challenge by HackerRank:
https://www.hackerrank.com/challenges/and-product
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    long int a, b;
    std::cin >> a >> b;

    long int x = a ^ b;
    long int next_power_of_two = 1L;
    while(next_power_of_two <= x)
    {
      next_power_of_two <<= 1;
    }

    std::cout << (a & (~(next_power_of_two - 1L))) << std::endl;
  }

  return 0;
}
