/*
Solution to the "LaptopBatteryLife" challenge by HackerRank:
https://www.hackerrank.com/challenges/battery
Written on 04-04-2017 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <cmath>
#include <iomanip>
#include <iostream>

int main(int argc, char **argv)
{
  double query;
  std::cin >> query;
  double ans = std::min(2.0 * query, 8.0);

  std::cout << std::setprecision(2) << std::fixed << ans << std::endl;

  return 0;
}
