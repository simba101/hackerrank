/*
Solution to the "TowerBreakers" challenge by HackerRank:
https://www.hackerrank.com/challenges/tower-breakers-1
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N, M;
    std::cin >> N >> M;
    std::cout << ((M == 1 || N % 2 == 0) ? "2" : "1") << std::endl;
  }

  return 0;
}
