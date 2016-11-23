/*
Solution to the "2D-Array" challenge by HackerRank:
https://www.hackerrank.com/challenges/2d-array
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

const int SIZE = 6;
const int INCREDIBLY_SMALL_HOURGLASS_VALUE = -9999;

int arr[SIZE][SIZE];

int main(int argc, char **argv)
{
  for(int y = 0; y < SIZE; ++y)
  {
    for(int x = 0; x < SIZE; ++x)
    {
      std::cin >> arr[y][x];
    }
  }

  int maxHourglassValue = INCREDIBLY_SMALL_HOURGLASS_VALUE;
  int currHourglassValue;
  // Calculates the hourglasses values:
  for(int y = 0; y < SIZE - 2; ++y)
  {
    for(int x = 0; x < SIZE - 2; ++x)
    {
      currHourglassValue =
          arr[y    ][x] + arr[y    ][x + 1] + arr[y    ][x + 2]
                        + arr[y + 1][x + 1]
        + arr[y + 2][x] + arr[y + 2][x + 1] + arr[y + 2][x + 2];

      if(currHourglassValue > maxHourglassValue)
      {
        maxHourglassValue = currHourglassValue;
      }
    }
  }

  std::cout << maxHourglassValue << std::endl;

  return 0;
}
