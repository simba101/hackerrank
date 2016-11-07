/*
Solution to the "LargestPermutation" challenge by HackerRank:
https://www.hackerrank.com/challenges/largest-permutation
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>

int N, K, number;
std::vector<int> numbers;

void print_array()
{
  for(int i = 0; i < N; ++i)
  {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char **argv)
{

  std::cin >> N >> K;
  numbers.reserve(N);

  // reads the permutation:
  for(int i = 0; i < N; ++i)
  {
    std::cin >> number;
    numbers.push_back(number);
  }

  // if the number of allowed swaps exceeds number of elements,
  if(K >= N - 1)
  {
    // simply sorts the array - this is the best permutation:
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
  }
  else
  {
    int swaps = 0;
    for(int s = 0; swaps < K; ++s)
    {
      // finds next greatest integer:
      int pos = s;
      while(numbers[pos] != (N - s))
      {
        pos += 1;
      }

      // if the next greatest element is already placed in its optimal place,
      // does not use the swap operation. Otherwise swaps it with s-th element:
      if(numbers[pos] != numbers[s])
      {
        std::swap(numbers[pos], numbers[s]);
        swaps += 1;
      }
    }
  }

  print_array();

  return 0;
}
