/*
Solution to the "MarsExploration" challenge by HackerRank:
https://www.hackerrank.com/challenges/mars-exploration
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  std::string message;
  std::cin >> message;

  int alters = 0;
  for(int i = 0; i < message.length() / 3; ++i)
  {
    if('S' != message[3 * i])
    {
      alters += 1;
    }
    if('O' != message[3 * i + 1])
    {
      alters += 1;
    }
    if('S' != message[3 * i + 2])
    {
      alters += 1;
    }
  }

  std::cout << alters << std::endl;

  return 0;
}
