/*
Solution to the "SimpleArraySum" challenge by HackerRank:
https://www.hackerrank.com/challenges/simple-array-sum
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int N;
  std::cin >> N;

  int sum = 0, number;

  for(int n = 0; n < N; ++n)
  {
    std::cin >> number;
    sum += number;
  }

  std::cout << sum << std::endl;

  return 0;
}
