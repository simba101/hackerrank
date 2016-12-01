/*
Solution to the "SavePrincess" challenge by HackerRank:
https://www.hackerrank.com/challenges/saveprincess
Written on 01-12-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <string>


int main(int argc, char **argv)
{
  // Reads in the size of the map. 3 <= size <= 100.
  int size;
  std::cin >> size;

  // Keeps the X and Y position of the princess and the bot, respectively:
  int princessX, princessY, botX, botY;

  // The map is a square consisting of size*size tiles.
  // Reads in the map. Each tile is guaranteed to be either:
  //  '-': denotes an empty tile,
  //  'm': denotes the position of the bot,
  //  'p': denotes the position of the princess.
  // Since the bot has to rendezvous with the princess, it's not
  // actually necessary to keep the whole map.
  std::string column;
  for(int y = 0; y < size; ++y)
  {
    // reads columns line by line, searching for the princess and the bot:
    std::cin >> column;
    for(int x = 0; x < column.length(); ++x)
    {
      // Is it the princess?:
      if('p' == column[x])
      {
        princessY = y;
        princessX = x;
      }
      // Or maybe is it the bot?:
      else if('m' == column[x])
      {
        botY = y;
        botX = x;
      }
    }
  }

  // Calculates the difference between bot's and princess' positions.
  // Results in a vector, which when anchored on bot's position
  // will point exactly to the princess' position.
  int diffX = princessX - botX;
  int diffY = princessY - botY;

  // Outputs a sequence of moves for a bot to reach the princess
  // in shortest possible time. Bot reaches the princess when the difference
  // between their positions reaches 0 along both X and Y axes.
  while(diffX != 0)
  {
    if(diffX < 0)
    {
      std::cout << "LEFT" << std::endl;
      diffX += 1;
    }
    else
    {
      std::cout << "RIGHT" << std::endl;
      diffX -= 1;
    }
  }
  while(diffY != 0)
  {
    if(diffY < 0)
    {
      std::cout << "UP" << std::endl;
      diffY += 1;
    }
    else
    {
      std::cout << "DOWN" << std::endl;
      diffY -= 1;
    }
  }

  return 0;
}
