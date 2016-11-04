/*
Solution to the "QuickSort2" challenge by HackerRank:
https://www.hackerrank.com/challenges/quicksort2
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>

void quicksort_while_printing_merged_bits(std::vector<int> &a)
{
  /*
  std::cout << "quicksort(";
  for(int i = 0; i < a.size(); ++i)
  {
    std::cout << a.at(i) << ", ";
  }
  std::cout << ")..." << std::endl;
  */

  if (a.size() < 2)
  {
  }
  else
  {
    std::vector<int> lower, greater;
    int pivot = a.at(0);
    for (int i = 1; i < a.size(); ++i)
    {
      if (a.at(i) <= pivot)
      {
        lower.push_back(a.at(i));
      }
      else
      {
        greater.push_back(a.at(i));
      }
    }

    quicksort_while_printing_merged_bits(lower);
    quicksort_while_printing_merged_bits(greater);

    int current = 0;
    // Merge lower array back into a:
    for (int l = 0; l < lower.size(); ++l)
    {
      a.at(current) = lower.at(l);
      std::cout << lower.at(l) << " ";
      ++current;
    }

    // Merge back the pivot element:
    a.at(current) = pivot;
    std::cout << pivot << " ";
    ++current;

    // Merge greater array back into a:
    for (int g = 0; g < greater.size(); ++g)
    {
      a.at(current) = greater.at(g);
      std::cout << greater.at(g) << " ";
      ++current;
    }

    std::cout << std::endl;
  }
}

int main(int argc, char **argv)
{
  std::vector<int> input;
  int length, val;

  std::cin >> length;
  input.reserve(length);
  for (int i = 0; i < length; ++i)
  {
    std::cin >> val;
    input.push_back(val);
  }

  quicksort_while_printing_merged_bits(input);

  return 0;
}
