/*
Solution to the "ArrayLeftRotation" challenge by HackerRank:
https://www.hackerrank.com/challenges/array-left-rotation/
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

const int MAX_ARRAY_SIZE = 100000;
int arr[MAX_ARRAY_SIZE];

int main(int argc, char **argv)
{
  int N, D;
  std::cin >> N >> D;
  for(int n = 0; n < N; ++n)
  {
    std::cin >> arr[n];
  }

  std::cout << arr[D] << " ";
  int d = (D + 1) % N;
  while(d != D)
  {
    std::cout << arr[d] << " ";
    d = (d + 1) % N;
  }

  std::cout << std::endl;


  return 0;
}
