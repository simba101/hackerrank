/*
Solution to the "SansaAndXor" challenge by HackerRank:
https://www.hackerrank.com/challenges/sansa-and-xor
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N;
    std::cin >> N;

    int ans = 0, num;
    for(int n = 0; n < N; ++n)
    {
      std::cin >> num;
      if((N % 2 == 1) && (n % 2 == 0))
      {
        ans ^= num;
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}
