/*
Solution to the "QuickSort1" challenge by HackerRank:
https://www.hackerrank.com/challenges/quicksort1
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  std::vector<int> input;
  std::vector<int> lesser;
  std::vector<int> equal;
  std::vector<int> greater;

  int length;

  std::cin >> length;
  input.reserve(length);
  for (int i = 0; i < length; ++i)
  {
    int value;
    std::cin >> value;
    input.push_back(value);
  }

  // 0-th element is considered a pivot.
  equal.push_back(input.at(0));

  // Partitions the elements into three distinct vectors:
  for (int i = 1; i < length; ++i)
  {
    if (input.at(i) < input.at(0))
    {
      lesser.push_back(input.at(i));
    }
    else if (input.at(i) > input.at(0))
    {
      greater.push_back(input.at(i));
    }
    else
    {
      equal.push_back(input.at(i));
    }
  }

  // Prints out the answer:
  for (int i = 0; i < lesser.size(); ++i)
  {
    std::cout << lesser.at(i) << " ";
  }
  for (int i = 0; i < equal.size(); ++i)
  {
    std::cout << equal.at(i) << " ";
  }
  for (int i = 0; i < greater.size(); ++i)
  {
    std::cout << greater.at(i) << " ";
  }

  return 0;
}
