/*
Solution to the "SavePrincess2" challenge by HackerRank:
https://www.hackerrank.com/challenges/saveprincess2
by simba (szczerbiakadam@gmail.com).
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

  // A redundant information - reads in the position of the bot.
  // This makes searching for the bot on the map unnecessary, but I kept
  // it to be consistent with the solution to the 1st version of the problem
  // (https://www.hackerrank.com/challenges/saveprincess).
  std::cin >> botY >> botX;

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

  // Outputs the next move for a bot to reach the princess.
  if(diffX < 0)
  {
    std::cout << "LEFT" << std::endl;
  }
  else if(diffX > 0)
  {
    std::cout << "RIGHT" << std::endl;
  }
  else if(diffY < 0)
  {
    std::cout << "UP" << std::endl;
  }
  else // the only other possible state is diffY > 0, i.e. bot should go down:
  {
    std::cout << "DOWN" << std::endl;
  }

  return 0;
}
