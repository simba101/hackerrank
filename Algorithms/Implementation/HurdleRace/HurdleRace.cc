/*
Solution to the "HurdleRace" challenge by HackerRank:
https://www.hackerrank.com/challenges/the-hurdle-race
Written on 09-03-2017 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>


int main(int argc, char **argv)
{
  int N, level, height, maxHeight = 0, answer;
  std::cin >> N >> level;

  for (int n = 0; n < N; ++n)
  {
    std::cin >> height;
    if (height > maxHeight)
    {
      maxHeight = height;
    }
  }

  answer = ((maxHeight - level > 0) ? (maxHeight - level) : 0);
  std::cout << answer << std::endl;

  return 0;
}
