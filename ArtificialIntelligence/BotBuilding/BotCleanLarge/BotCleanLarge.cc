/*
Solution to the "BotCleanLarge" challenge by HackerRank:
https://www.hackerrank.com/challenges/botcleanlarge
Written on 02-12-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <string>
#include <vector>

// Represents any object on the map - be it a dirt or a robot.
struct Object
{
  Object(int y, int x) : Y(y), X(x) {}

  // Returns the manhattan distance to any other Object:
  int manhattan(Object const &other)
  {
    return std::abs(Y - other.Y) + std::abs(X - other.X);
  }

  int Y;
  int X;
};

int main(int argc, char **argv)
{
  int botY, botX;
  int sizeY, sizeX;
  std::string column;
  std::vector<Object> dirts;
  std::vector<int> distances;

  // Reads in the current position of the bot:
  std::cin >> botY >> botX;

  // Initializes a bot-Object:
  Object botObject(botY, botX);

  // Reads in the map:
  std::cin >> sizeY >> sizeX;
  for(int y = 0; y < sizeY; ++y)
  {
    std::cin >> column;
    for(int x = 0; x < sizeX; ++x)
    {
      if('d' == column[x])
      {
        Object dirt(y, x);

        // Appends found dirt to the vector:
        dirts.push_back(dirt);

        // Appends the distance between the bot and the dirt to the vector:
        distances.push_back(botObject.manhattan(dirt));
      }
    }
  }

  // Performs actions only when there is some dirt to clean:
  if(!dirts.empty())
  {
    // The action to be performed by the bot in this step, e.g. "CLEAN".
    std::string action;

    // Finds the closest object:
    int closestDist = botObject.manhattan(dirts[0]);
    int closestDirt = 0;
    for(int d = 1; d < dirts.size(); ++d)
    {
      // Calculates the distance betweeen d-th dirt and the bot:
      int dist = botObject.manhattan(dirts[d]);
      if(dist < closestDist)
      {
        closestDist = dist;
        closestDirt = d;
      }
    }

    // Now that the closest dirt has been found, the bot should
    // navigate right above it and once there, clean it:
    if(0 == closestDist)
    {
      action = "CLEAN";
    }
    else if(dirts[closestDirt].Y < botY)
    {
      action = "UP";
    }
    else if(dirts[closestDirt].Y > botY)
    {
      action = "DOWN";
    }
    else if(dirts[closestDirt].X < botX)
    {
      action = "LEFT";
    }
    else // Exhausted all the other possibilities, the dirt is to the right:
    {
      action = "RIGHT";
    }

    // Performs the action:
    std::cout << action << std::endl;
  }

  return 0;
}
