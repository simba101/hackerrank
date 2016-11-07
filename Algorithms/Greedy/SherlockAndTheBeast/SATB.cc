/*
Solution to the "SherlockAndTheBeast" challenge by HackerRank:
https://www.hackerrank.com/challenges/sherlock-and-the-beast
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int t, T;
  std::cin >> T;
  for(int t = 0; t < T; ++t)
  {
    int noOfDigits;
    std::cin >> noOfDigits;

    if(noOfDigits == 1 || noOfDigits == 2 || noOfDigits == 4 || noOfDigits == 7)
    {
      std::cout << -1 << std::endl;
    }
    else
    {
      int bestFivesFit = 0;
      int bestThreesFit = 0;
      while(noOfDigits % 3 != 0)
      {
        noOfDigits -= 5;
        bestThreesFit += 5;
      }
      bestFivesFit = noOfDigits;

      for(int i = 0; i < bestFivesFit; ++i)
      {
        std::cout << "5";
      }
      for(int i = 0; i < bestThreesFit; ++i)
      {
        std::cout << "3";
      }
      std::cout << std::endl;
    }
  }

  return 0;
}
