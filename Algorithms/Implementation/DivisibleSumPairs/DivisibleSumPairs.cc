/*
Solution to the "DivisibleSumPairs" challenge by HackerRank:
https://www.hackerrank.com/challenges/divisible-sum-pairs
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  int count, k;
  std::cin >> count >> k;
  std::vector<int> N;
  N.resize(count);
  int pairs = 0;

  for(int i = 0; i < count; ++i)
  {
    std::cin >> N[i];
  }

  for(int i = 0; i < count - 1; ++i)
  {
    for(int j = i + 1; j < count; ++j)
    {
      if((N[i] + N[j]) % k == 0)
      {
        ++pairs;
      }
    }
  }

  std::cout << pairs << std::endl;
  return 0;
}
