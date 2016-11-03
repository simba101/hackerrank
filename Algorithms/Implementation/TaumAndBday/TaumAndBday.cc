/*
Solution to the "TaumAndBday" challenge by HackerRank:
https://www.hackerrank.com/challenges/taum-and-bday
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    unsigned long long B, W;
    unsigned long long X, Y, Z;
    unsigned long long totalCost = 0;

    std::cin >> B >> W >> X >> Y >> Z;

    unsigned long long bOptimalCost = X;
    if(Y + Z < X)
    {
      bOptimalCost = Y + Z;
    }

    unsigned long long wOptimalCost = Y;
    if(X + Z < Y)
    {
      wOptimalCost = X + Z;
    }

    totalCost = (bOptimalCost * B) + (wOptimalCost * W);
    std::cout << totalCost << std::endl;
  }

  return 0;
}
