/*
Solution to the "StrangeCounter" challenge by HackerRank:
https://www.hackerrank.com/challenges/strange-code
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <cmath>

int main(int argc, char **argv)
{
  long long t;
  std::cin >> t;

  //unsigned long long group = std::floor(std::log2(((t - 1) / 3) + 1));

  long long remainder = 3LL;
  while (t > remainder)
  {
    t -= remainder;
    remainder *= 2LL;
  }

  long long ans = remainder - t + 1LL;

  std::cout << ans << std::endl;

  return 0;
}
