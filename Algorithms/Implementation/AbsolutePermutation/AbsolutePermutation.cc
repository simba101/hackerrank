/*
Solution to the "AbsolutePermutation" challenge by HackerRank:
https://www.hackerrank.com/challenges/absolute-permutation
Written on 09-02-2017 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <vector>
#include <algorithm>


int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for (int t = 0; t < T; ++t)
  {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n); // a vector with n ints

    if((0 == k) || (0 == n % (2 * k)))
    {
      // Needs at least std=c++11 flag.
      // Fills in the vector with increasing values starting from 1:
      std::iota(v.begin(), v.end(), 1);

      if(0 != k)
      {
        for(int o = 0; o < (n / (2 * k)); ++o) // outer loop
        {
          for(int i = 1; i <= k; ++i) // inner loop
          {
            int a = (2 * k) * o     + i - 1;
            int b = (2 * k) * o + k + i - 1;
            std::swap(v[a], v[b]);
          }
        }

      }

      for(int e = 0; e < v.size(); ++e)
      {
        std::cout << v[e] << " ";
      }
      std::cout << std::endl;
    }
    else
    {
      std::cout << "-1" << std::endl;
    }


  }

  return 0;
}
