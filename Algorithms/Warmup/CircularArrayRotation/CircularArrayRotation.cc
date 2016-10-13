/*
Solution to the "CircularArrayRotation" challenge by HackerRank:
https://www.hackerrank.com/challenges/circular-array-rotation
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  int n, k, q, temp, query;
  std::vector<int> arr;

  std::cin >> n >> k >> q;
  k = k % n;

  arr.reserve(n);
  for (int i = 0; i < n; ++i)
  {
    std::cin >> temp;
    arr.push_back(temp);
  }

  for (int i = 0; i < q; ++i)
  {
    std::cin >> query;
    std::cout << arr.at((n + query - k) % n) << std::endl;
  }

  return 0;
}
