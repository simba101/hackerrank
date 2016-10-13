/*
Solution to the "AVeryBigSum" challenge by HackerRank:
https://www.hackerrank.com/challenges/a-very-big-sum
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int N;
  std::cin >> N;

  unsigned long long int sum = 0ULL;
  unsigned long long int number;

  for(int n = 0; n < N; ++n)
  {
    std::cin >> number;
    sum += number;
  }

  std::cout << sum << std::endl;

  return 0;
}
