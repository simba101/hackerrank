/*
Solution to the "TheMaximumSubarray" challenge by HackerRank:
https://www.hackerrank.com/challenges/maxsubarray
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T, t, n, maxEndingHere, maxSoFar, maxNonContiguous, number, maxNumber;

  std::cin >> T;
  for(int t = 0; t < T; ++t)
  {
    maxEndingHere = 0;
    maxSoFar = 0;
    maxNonContiguous = 0;
    maxNumber = -2147483648;

    std::cin >> n;
    for(int i = 0; i < n; ++i)
    {
      std::cin >> number;
      if(number > maxNumber)
      {
        maxNumber = number;
      }
      if(number > 0)
      {
        maxNonContiguous += number;
      }
      maxEndingHere = maxEndingHere + number > 0 ? maxEndingHere + number : 0;
      maxSoFar = (maxEndingHere > maxSoFar) ? maxEndingHere : maxSoFar;
    }

    // if all the numbers were negative, then the above algorithm outputs 0
    // (select an empty set from the array to maximize sum). Since at least one
    // element has to be selected, maxNumber should be printed out instead:
    std::cout << ((maxNumber < 0) ? maxNumber : maxSoFar) << " "
              << ((maxNumber < 0) ? maxNumber : maxNonContiguous) << std::endl;
  }

  return 0;
}
