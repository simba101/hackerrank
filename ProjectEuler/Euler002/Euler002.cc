/*
Solution to the "Euler002" challenge by HackerRank:
https://www.hackerrank.com/contests/projecteuler/challenges/euler002
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    unsigned long long N;
    std::cin >> N;
    unsigned long long last = 2ULL;
    unsigned long long previous = 8ULL;
    unsigned long long sum = 10ULL;
    unsigned long long current = (4ULL * previous) + last;

    while(current <= N)
    {
      sum += current;
      last = previous;
      previous = current;
      current = (4ULL * previous) + last;
    }

    std::cout << sum << std::endl;
  }

  return 0;
}
