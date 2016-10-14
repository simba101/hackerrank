/*
Solution to the "SaveThePrisoner" challenge by HackerRank:
https://www.hackerrank.com/challenges/save-the-prisoner
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    long int N, M, S;
    std::cin >> N >> M >> S;

    long int ans = ((M + (S - 1) - 1) % N) + 1; // 1-indexed prisoners
    std::cout << ans << std::endl;
  }

  return 0;
}
