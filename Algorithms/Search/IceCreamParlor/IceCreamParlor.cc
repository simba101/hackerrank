/*
Solution to the "IceCreamParlor" challenge by HackerRank:
https://www.hackerrank.com/challenges/icecream-parlor
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>

void print_list(std::vector<int> l)
{
  for (int n = 0; n < l.size(); ++n)
  {
    std::cout << l.at(n) << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for (int t = 0; t < T; ++t)
  {
    int M;
    std::cin >> M;

    int N;
    std::cin >> N;

    std::vector<int> list;
    list.reserve(N);

    for (int n = 0; n < N; ++n)
    {
      int val;
      std::cin >> val;
      list.push_back(val);
    }

    // std::cout << "List: ";
    // print_list(list);

    std::vector<int> sorted;
    for(int n = 0; n < N; ++n)
    {
      sorted.push_back(list.at(n));
    }
    std::sort(sorted.begin(), sorted.end());

    // std::cout << "Sorted: ";
    // print_list(sorted);

    int low = 0;
    int high = N - 1;
    bool found = false;

    while ((!found) && (low < high))
    {
      int sum = sorted.at(low) + sorted.at(high);
      // std::cout << "Low: " << low << ", high: " << high << "sum: " << sum << std::endl;
      if (sum == M)
      {
        // std::cout << "Sum == M!" << std::endl;
        found = true;
      }
      else if (sum < M)
      {
        // std::cout << "sum < M (" << sum << " < " << M << ")" << std::endl;
        // Keeps adding items from the left until the sum is >= M:
        low += 1;
      }
      else
      {
        // std::cout << "sum > M (" << sum << " > " << M << ")" << std::endl;
        high -= 1;
      }
    }

    if (found)
    {
      int low_pos = -1, high_pos = -1;
      for (int n = 0; n < N; ++n)
      {
        if (list.at(n) == sorted.at(low))
        {
          low_pos = n + 1;
        }
      }

      for (int n = 0; n < N; ++n)
      {
        if ((list.at(n) == sorted.at(high)) && (n != low_pos - 1))
        {
          high_pos = n + 1;
        }
      }
      /*
      for (int n = 0; n < N; ++n)
      {
        if ((!low_pos_found) && (list.at(n) == sorted.at(low)))
        {
          low_pos = n + 1;
          std::cout << "list.at(" << n << ") [" << list.at(n)
              << "] == sorted.at(" << low << ") [" << sorted.at(low) << "]" << std::endl;
          std::cout << "Therefore, low_pos = " << low_pos << std::endl;
        }
        else if (list.at(n) == sorted.at(high))
        {
          high_pos = n + 1;
          std::cout << "list.at(" << n << ") [" << list.at(n)
              << "] == sorted.at(" << high << ") [" << sorted.at(high) << "]" << std::endl;
          std::cout << "Therefore, high_pos = " << high_pos << std::endl;
        }
      }
      */

      if (low_pos > high_pos)
      {
        std::swap(low_pos, high_pos);
      }

      std::cout << low_pos << " " << high_pos << std::endl;
    }
  }

  return 0;
}
