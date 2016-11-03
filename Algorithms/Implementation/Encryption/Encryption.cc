/*
Solution to the "Encryption" challenge by HackerRank:
https://www.hackerrank.com/challenges/encryption
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <cmath>
#include <string>

const int BUFSIZE = 200;
const int MATRIXSIZE = 10;

int main(int argc, char **argv)
{
  std::string bufin;
  char buffer[BUFSIZE];
  char matrix[MATRIXSIZE][MATRIXSIZE];

  for(int i = 0; i < BUFSIZE; ++i)
  {
    buffer[i] = '\0';
  }

  for(int h = 0; h < MATRIXSIZE; ++h)
  {
    for(int w = 0; w < MATRIXSIZE; ++w)
    {
      matrix[h][w] = '\0';
    }
  }

  std::getline(std::cin, bufin);

  int length = 0, width, height;

  for(int pos = 0; pos < bufin.length(); ++pos)
  {
    if(bufin[pos] != ' ') // the space character
    {
      buffer[length] = bufin[pos];
      ++length;
    }
  }

  width = std::ceil(std::sqrt(length));
  height = length / width;
  if(length % width != 0)
  {
    height += 1;
  }

  for(int p = 0; p < length; ++p)
  {
    matrix[p / width][p % width] = buffer[p];
  }

  for(int w = 0; w < width; ++w)
  {
    for(int h = 0; h < height; ++h)
    {
      if(matrix[h][w] != '\0')
      {
        std::cout << matrix[h][w];
      }
    }
    std::cout << " ";
  }
  std::cout << std::endl;

  return 0;
}
