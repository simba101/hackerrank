/*
Solution to the "MiniMaxSum" challenge by HackerRank:
https://www.hackerrank.com/challenges/mini-max-sum
Written on 24-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <algorithm>
#include <vector>

const int LENGTH = 5; // the size of the array, =5 for this challenge.

int main(int argc, char **argv)
{
  std::vector<long int> arr(LENGTH);

  for(int i = 0; i < LENGTH; ++i)
  {
    std::cin >> arr[i];
  }

  // sorts the array contents in a non-descending order:
  std::sort(arr.begin(), arr.end());

  long int minSum = arr[0] + arr[1] + arr[2] + arr[3];
  long int maxSum = arr[1] + arr[2] + arr[3] + arr[4];

  std::cout << minSum << " " << maxSum << std::endl;

  return 0;
}
