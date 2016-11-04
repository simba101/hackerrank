/*
Solution to the "CountingSort2" challenge by HackerRank:
https://www.hackerrank.com/challenges/countingsort2
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

  for(int number = 0; number < NUMBERS; ++number)
  {
    for(int i = 0; i < count[number]; ++i)
    {
      std::cout << number << " ";
    }
  }
  std::cout << std::endl;

  return 0;
}

