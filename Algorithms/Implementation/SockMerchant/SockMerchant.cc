/*
Solution to the "SockMerchant" challenge by HackerRank:
https://www.hackerrank.com/challenges/sock-merchant
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

constexpr int MAX_COLORS = 100;

int main(int argc, char **argv)
{
  int socks[MAX_COLORS + 1] = {0}; // for colors indexed in range <1, 100>

  int N, sock;
  std::cin >> N;
  for(int n = 0; n < N; ++n)
  {
    std::cin >> sock;
    socks[sock] += 1;
  }

  int pairs = 0;
  for(int c = 1; c <= MAX_COLORS; ++c)
  {
    pairs += socks[c] / 2;
  }

  std::cout << pairs << std::endl;

  return 0;
}
