/*
Solution to the "CountingSort3" challenge by HackerRank:
https://www.hackerrank.com/challenges/countingsort3
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

const int NUMBERS = 100;

int main(int argc, char **argv)
{
  int count[NUMBERS] = {0};
  int N, number;
  std::string temp;

  std::cin >> N;

  for(int n = 0; n < N; ++n)
  {
    std::cin >> number;
    std::cin >> temp;
    count[number] += 1;
  }

  int totalSum = 0;
  for(int i = 0; i < NUMBERS; ++i)
  {
    totalSum += count[i];
    std::cout << totalSum << " ";
  }
  std::cout << std::endl;

  return 0;
}
