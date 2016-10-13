/*
Solution to the "DiagonalDifference" challenge by HackerRank:
https://www.hackerrank.com/challenges/diagonal-difference
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int n;
  std::cin >> n;

  int sumOverPrimaryDiagonal = 0, sumOverSecondaryDiagonal = 0;
  int number;

  for(int y = 0; y < n; ++y)
  {
    for(int x = 0; x < n; ++x)
    {
      std::cin >> number;
      if(x == y)
      {
        // This number lies on the primary diagonal.
        sumOverPrimaryDiagonal += number;
      }
      if(x + y == n - 1)
      {
        // This number lies on the secondary diagonal.
        sumOverSecondaryDiagonal += number;
      }
    }
  }

  int ans = std::abs(sumOverPrimaryDiagonal - sumOverSecondaryDiagonal);
  std::cout << ans << std::endl;

  return 0;
}
