/*
Solution to the "Staircase" challenge by HackerRank:
https://www.hackerrank.com/challenges/staircase
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int N;
  std::cin >> N;

  for(int level = 1; level <= N; ++level)
  {
    for(int b = 0; b < N - level; ++b)
    {
      std::cout << " ";
    }
    for(int s = 0; s < level; ++s)
    {
      std::cout << "#";
    }

    std::cout << std::endl;
  }

  return 0;
}
