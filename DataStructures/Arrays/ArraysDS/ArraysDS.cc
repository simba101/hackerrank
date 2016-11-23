/*
Solution to the "ArraysDS" challenge by HackerRank:
https://www.hackerrank.com/challenges/arrays-ds
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

const int N_MAX = 1000;
int arr[N_MAX];

int main(int argc, char **argv)
{
  int N;
  std::cin >> N;

  for(int n = 0; n < N; ++n)
  {
    std::cin >> arr[n];
  }

  // outputs the numbers in the reverse order:
  for(int n = N - 1; n >= 0; --n)
  {
    std::cout << arr[n] << " ";
  }
  std::cout << std::endl;

  return 0;
}
