/*
Solution to the "Euler009" challenge by HackerRank:
https://www.hackerrank.com/contests/projecteuler/challenges/euler009
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

bool isPythagoreanTriplet(int a, int b, int c)
{
  return ((a * a) + (b * b) == (c * c));
}

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N;
    std::cin >> N;

    int answer = -1;

    // N has to be even, otherwise there will be no such pythagorean triplet:
    if(N % 2 == 0)
    {
      for(int a = 3; a <= N / 3; ++a)
      {
        int aMinusN = a - N;
        int b = ((a * a) - (aMinusN * aMinusN)) / (2 * aMinusN);
        int c = N - a - b;
        if((b > 0) && (c > 0) && (isPythagoreanTriplet(a, b, c)))
        {
          if(a * b * c > answer)
          {
            answer = a * b * c;
          }
        }
      }
    }

    std::cout << answer << std::endl;
  }

  return 0;
}
