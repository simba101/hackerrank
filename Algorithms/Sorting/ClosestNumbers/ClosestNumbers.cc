/*
Solution to the "ClosestNumbers" challenge by HackerRank:
https://www.hackerrank.com/challenges/closest-numbers
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <algorithm>
#include <vector>

const int NMAX = 200000;

int main(int argc, char **argv)
{
  std::vector<int> arr;
  std::vector<int> diffs;
  int N, number;
  std::cin >> N;
  arr.reserve(N);
  diffs.reserve(N - 1);

  // Reads N integers from the stdin and puts them in an array:
  for(int n = 0; n < N; ++n)
  {
    std::cin >> number;
    arr.push_back(number);
  }

  // sorts the array:
  std::sort(std::begin(arr), std::end(arr));

  // Calculates the differences between each pair of two consecutive elements
  // and stores these differences in an array. Also keeps track of the least
  // value of differences:
  int mindiff = 20000001, diff; // 2 * 10e7 is a valid range of elements.
  for(int n = 0; n < N - 1; ++n)
  {
    diff = arr[n + 1] - arr[n];
    diffs.push_back(diff);
    if(diff < mindiff)
    {
      mindiff = diff;
    }
  }

  // Traverses the mindiff array. When current diff == mindiff,
  // prints out associated pair and a space character:
  for(int n = 0; n < N - 1; ++n)
  {
    if(diffs[n] == mindiff)
    {
      std::cout << arr[n] << " " << arr[n + 1] << " ";
    }
  }

  std::cout << std::endl;

  return 0;
}
