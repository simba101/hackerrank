/*
Solution to the "ModifiedKaprekarNumbers" challenge by HackerRank:
https://www.hackerrank.com/challenges/kaprekar-numbers
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int knums[] = { 1, 9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4950, 5050, 7272,
    7777, 9999, 17344, 22222, 77778, 82656, 95121, 99999 };
const int KNUMS_LENGTH = 21;

int main(int argc, char **argv)
{
  int p, q;
  std::cin >> p >> q;
  bool found = false;

  for(int k = 0; k < KNUMS_LENGTH; ++k)
  {
    if(knums[k] >= p && knums[k] <= q)
    {
      found = true;
      std::cout << knums[k] << " ";
    }
  }

  if(!found)
    std::cout << "INVALID RANGE";

  std::cout << std::endl;

  return 0;
}
