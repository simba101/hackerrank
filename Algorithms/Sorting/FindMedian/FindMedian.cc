/*
Solution to the "FindMedian" challenge by HackerRank:
https://www.hackerrank.com/challenges/find-median
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char **argv)
{
  std::vector<short int> list;
  int count;
  short int elem;

  std::cin >> count;
  list.reserve(count);

  for(int i = 0; i < count; ++i)
  {
    std::cin >> elem;
    list.push_back(elem);
  }

  std::sort(list.begin(), list.end());
  std::cout << list.at(list.size() / 2) << std::endl;

  return 0;
}
