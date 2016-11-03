/*
Solution to the "Cavity Map" challenge by HackerRank:
https://www.hackerrank.com/challenges/cavity-map
by simba (szczerbiakadam@gmail.com)
*/

#include <iostream>

const int NLIMIT = 100;

int main(int argc, char **argv)
{
  char origmap[NLIMIT][NLIMIT];
  char newmap[NLIMIT][NLIMIT];
  char buffer[NLIMIT + 1];
  int N;

  std::cin >> N;
  for(int h = 0; h < N; ++h)
  {
    std::cin >> buffer;
    for(int w = 0; w < N; ++w)
    {
      origmap[h][w] = buffer[w];
      newmap[h][w] = buffer[w];
    }
  }

  for(int h = 1; h < N - 1; ++h)
  {
    for(int w = 1; w < N - 1; ++w)
    {
      if(
          (origmap[h][w] > origmap[h - 1][w]) &&
          (origmap[h][w] > origmap[h][w - 1]) &&
          (origmap[h][w] > origmap[h][w + 1]) &&
          (origmap[h][w] > origmap[h + 1][w])
        )
      {
        newmap[h][w] = 'X';
      }
    }
  }

  for(int h = 0; h < N; ++h)
  {
    for(int w = 0; w < N; ++w)
    {
      std::cout << newmap[h][w];
    }
    std::cout << std::endl;
  }

  return 0;
}
