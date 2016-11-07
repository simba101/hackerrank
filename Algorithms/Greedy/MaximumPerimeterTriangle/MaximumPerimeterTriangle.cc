/*
Solution to the "MaximumPerimeterTriangle" challenge by HackerRank:
https://www.hackerrank.com/challenges/maximum-perimeter-triangle
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>           // for the vectors.
#include <algorithm>        // for sorting a vector.

int main(int argc, char **argv)
{
  int N;
  std::vector<int> sticks;

  std::cin >> N;
  sticks.resize(N);
  for(int n = 0; n < N; ++n)
  {
    std::cin >> sticks[n];
  }

  std::sort(sticks.begin(), sticks.end());

  int c = N - 1;            // c - "currently analyzed stick".
  while((c >= 2) && (sticks[c - 2] + sticks[c - 1] <= sticks[c]))
  {
    c -= 1;
  }

  if(c >= 2)
  {
    std::cout << sticks[c - 2] << " " << sticks[c - 1] << " "
              << sticks[c] << std::endl;
  }
  else
  {
    std::cout << "-1" << std::endl;
  }

  return 0;
}

