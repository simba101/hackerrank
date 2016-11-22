/*
Solution to the "Euler011" challenge by HackerRank:
https://www.hackerrank.com/contests/projecteuler/challenges/euler011
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

const int DIM = 20;

int n[DIM][DIM]; // n stays for "numbers".

int main(int argc, char **argv)
{
  // reads the data:
  for(int y = 0; y < DIM; ++y)
  {
    for(int x = 0; x < DIM; ++x)
    {
      std::cin >> n[x][y];
    }
  }

  int maxProduct = 0;
  int product;
  for(int y = 0; y <= DIM - 4; ++y)
  {
    for(int x = 0; x <= DIM - 4; ++x)
    {
      // checks along X axis:
      product = n[x][y] * n[x + 1][y] * n[x + 2][y] * n[x + 3][y];
      if(product > maxProduct)
      {
        maxProduct = product;
      }

      // checks along Y axis:
      product = n[x][y] * n[x][y + 1] * n[x][y + 2] * n[x][y + 3];
      if(product > maxProduct)
      {
        maxProduct = product;
      }

      // checks along forward-diagonal (\) axis:
      product = n[x][y] * n[x + 1][y + 1] * n[x + 2][y + 2] * n[x + 3][y + 3];
      if(product > maxProduct)
      {
        maxProduct = product;
      }

      // checks along backward-diagonal (/) axis:
      product = n[x][y + 3] * n[x + 1][y + 2] * n[x + 2][y + 1] * n[x + 3][y];
      if(product > maxProduct)
      {
        maxProduct = product;
      }
    }
  }

  // Y-axis checks for the last three columns:
  for(int y = 0; y <= DIM - 4; ++y)
  {
    for(int x = DIM - 3; x < DIM; ++x)
    {
      product = n[x][y] * n[x][y + 1] * n[x][y + 2] * n[x][y + 3];
      if(product > maxProduct)
      {
        maxProduct = product;
      }
    }
  }

  // X-axis checks for the last three rows:
  for(int y = DIM - 3; y < DIM; ++y)
  {
    for(int x = 0; x <= DIM - 4; ++x)
    {
      product = n[x][y] * n[x + 1][y] * n[x + 2][y] * n[x + 3][y];
      if(product > maxProduct)
      {
        maxProduct = product;
      }
    }
  }

  std::cout << maxProduct << std::endl;
  return 0;
}
