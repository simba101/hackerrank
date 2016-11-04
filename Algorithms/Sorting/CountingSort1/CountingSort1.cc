/*
Solution to the "CountingSort1" challenge by HackerRank:
https://www.hackerrank.com/challenges/countingsort1
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

const int NUMBERS = 100;

int main(int argc, char **argv)
{
  int count[NUMBERS] = {0};
  int N, number;
  std::cin >> N;

  for(int n = 0; n < N; ++n)
  {
    std::cin >> number;
    count[number] += 1;
  }

  for(int i = 0; i < NUMBERS; ++i)
  {
    std::cout << count[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
