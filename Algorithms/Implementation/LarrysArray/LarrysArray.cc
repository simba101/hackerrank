/*
Solution to the "LarrysArray" challenge by HackerRank:
https://www.hackerrank.com/challenges/larrys-array
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>

inline int minOfThree(int a, int b, int c)
{
  return ((a < b && a < c) ? a : (b < c ? b : c));
}

inline void dump_array(std::vector<int>& array)
{
  for(auto it = array.begin(); it != array.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N;
    std::cin >> N;
    std::vector<int> data;
    data.resize(N);
    for(int n = 0; n < N; ++n)
    {
      std::cin >> data[n];
    }

    // std::cout << "Before: "; dump_array(data);

    // Three-bubble-sort implementation:
    for(int o = 0; o < N - 2; ++o) // outer loop (o)
    {
      for(int i = N - 3; i >= o; --i) // inner loop (i)
      {
        int min = minOfThree(data[i], data[i + 1], data[i + 2]);
        while(data[i] != min)
        {
          int temp = data[i];
          data[i] = data[i + 1];
          data[i + 1] = data[i + 2];
          data[i + 2] = temp;
        }
      }
      // std::cout << "o: " << o << ", array: "; dump_array(data);
    }

    // if it is sorted, then the robot may do it as well:
    if(std::is_sorted(data.begin(), data.end()))
    {
      std::cout << "YES" << std::endl;
    }
    else
    {
      std::cout << "NO" << std::endl;
    }
  }

  return 0;
}
