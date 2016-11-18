/*
Solution to the "SumVsXor" challenge by HackerRank:
https://www.hackerrank.com/challenges/sum-vs-xor
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  unsigned long long int N;
  std::cin >> N;

  int noOfZeroesInBinaryRepresentation = 0;
  while (N > 0)
  {
    if (0 == (N & 1))
    {
      noOfZeroesInBinaryRepresentation += 1;
    }
    N >>= 1;
  }

  unsigned long long int ans = 1ULL << noOfZeroesInBinaryRepresentation;
  std::cout << ans << std::endl;

  return 0;
}
