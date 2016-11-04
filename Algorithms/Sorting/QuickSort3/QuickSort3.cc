/*
Solution to the "QuickSort3" challenge by HackerRank:
https://www.hackerrank.com/challenges/quicksort3
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm> // for std::swap().

int partition(std::vector<int> &data, int start, int end)
{
  int i = start;
  for (int j = start; j < end; ++j)
  {
    if (data.at(j) <= data.at(end))
    {
      std::swap(data.at(i), data.at(j));
      ++i;
    }
  }
  std::swap(data.at(i), data.at(end));
  return i;
}

void quicksort_in_place_with_printing(std::vector<int> &data, int start, int end)
{
  // only quicksorts-in-place-with-printing bits of at least 2 elements long:
  if (start < end)
  {
    int p = partition(data, start, end);

    // Finally, prints the entire array:
    for (int i = 0; i < data.size(); ++i)
    {
      std::cout << data.at(i) << " ";
    }
    std::cout << std::endl;

    quicksort_in_place_with_printing(data, start, p - 1);
    quicksort_in_place_with_printing(data, p + 1, end);
  }
}

int main(int argc, char **argv)
{
  std::vector<int> input;
  int length, val;

  std::cin >> length;
  input.reserve(length);
  for(int i = 0; i < length; ++i)
  {
    std::cin >> val;
    input.push_back(val);
  }

  quicksort_in_place_with_printing(input, 0, input.size() - 1);

  return 0;
}
