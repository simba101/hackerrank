/*
Solution to the "PlusMinus" challenge by HackerRank:
https://www.hackerrank.com/challenges/plus-minus
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <iomanip>

int main(int argc, char **argv)
{
  int positive = 0;
  int negative = 0;
  int zeroes = 0;

  int n, number;
  std::cin >> n;

  for(int i = 0; i < n; ++i)
  {
    std::cin >> number;
    if(number > 0)
      ++positive;
    else if(number < 0)
      ++negative;
    else
      ++zeroes;
  }

  double positiveF = static_cast<double>(positive) / n;
  double negativeF = static_cast<double>(negative) / n;
  double zeroesF = static_cast<double>(zeroes) / n;

  std::cout << std::setprecision(6) << std::fixed;
  std::cout << positiveF << std::endl
            << negativeF << std::endl
            << zeroesF << std::endl;

  return 0;
}
