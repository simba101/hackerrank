/*
Solution to the "MissingNumbers" challenge by HackerRank:
https://www.hackerrank.com/challenges/missing-numbers
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

const int CONSTRAINT = 10000 + 1;

int main(int argc, char **argv)
{
  int freq[CONSTRAINT] = {0};

  int N, M, val;
  std::cin >> N;
  for (int n = 0; n < N; ++n)
  {
    std::cin >> val;
    --freq[val];
  }

  std::cin >> M;
  for (int m = 0; m < M; ++m)
  {
    std::cin >> val;
    ++freq[val];
  }

  for (int i = 0; i < CONSTRAINT; ++i)
  {
    if (freq[i] > 0)
    {
      std::cout << i << " ";
    }
  }

  std::cout << std::endl;

  return 0;
}
