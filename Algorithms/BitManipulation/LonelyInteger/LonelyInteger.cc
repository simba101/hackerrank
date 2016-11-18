/*
Solution to the "LonelyInteger" challenge by HackerRank:
https://www.hackerrank.com/challenges/lonely-integer
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int N;
  std::cin >> N;

  int ans = 0, num;
  for(int n = 0; n < N; ++n)
  {
    std::cin >> num;
    ans ^= num;
  }

  std::cout << ans << std::endl;

  return 0;
}
