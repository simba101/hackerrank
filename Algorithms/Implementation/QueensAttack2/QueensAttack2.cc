/*
Solution to the "QueensAttack2" challenge by HackerRank:
https://www.hackerrank.com/challenges/queens-attack-2
Written on 16-03-2017 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>

inline int min(int a, int b)
{
  return (a < b) ? a : b;
}

struct Position
{
  int x;
  int y;
};

int main(int argc, char **argv)
{
  int N;
  int obstaclesCount;

  Position queen;
  Position obstacle; // for holding each processed obstacle

  // The obstacles along 8 attack lines denoted as compass directions
  Position obstacleNW;
  Position obstacleN;
  Position obstacleNE;
  Position obstacleE;
  Position obstacleSE;
  Position obstacleS;
  Position obstacleSW;
  Position obstacleW;


  // Reads in the data:
  std::cin >> N >> obstaclesCount;
  std::cin >> queen.y >> queen.x;

  // Sets up the obstacles so that they indicate the borders of the chessboard:
  obstacleS.x = queen.x;
  obstacleS.y = 0;
  obstacleN.x = queen.x;
  obstacleN.y = N + 1;
  obstacleW.x = 0;
  obstacleW.y = queen.y;
  obstacleE.x = N + 1;
  obstacleE.y = queen.y;

  // diagonal obstacles are a little bit more tricky:
  int distN = (N + 1) - queen.y;
  int distE = (N + 1) - queen.x;
  int distS = queen.y; // == queen.y - 0
  int distW = queen.x;

  // for each of the four diagonal obstacles, gets the distance of the closest
  // one of two relevant chessboard borders and puts the obstacle
  // at this distance on said diagonal:
  int distNW = min(distN, distW);
  obstacleNW.y = queen.y + distNW;
  obstacleNW.x = queen.x - distNW;

  int distNE = min(distN, distE);
  obstacleNE.y = queen.y + distNE;
  obstacleNE.x = queen.x + distNE;

  int distSE = min(distS, distE);
  obstacleSE.y = queen.y - distSE;
  obstacleSE.x = queen.x + distSE;

  int distSW = min(distS, distW);
  obstacleSW.y = queen.y - distSW;
  obstacleSW.x = queen.x - distSW;


  for (int obs = 0; obs < obstaclesCount; ++obs)
  {
    std::cin >> obstacle.y >> obstacle.x;
    if (obstacle.y == queen.y)
    { // obstacle lies on horizontal line of attack ("-")
      if ((obstacle.x < queen.x) && (obstacle.x > obstacleW.x))
      {
        obstacleW.x = obstacle.x;
      }
      else if ((obstacle.x > queen.x) && (obstacle.x < obstacleE.x))
      {
        obstacleE.x = obstacle.x;
      }
    }
    else if (obstacle.x == queen.x)
    { // obstacle lies on vertical line of attack ("|")
      if ((obstacle.y < queen.y) && (obstacle.y > obstacleS.y))
      {
        obstacleS.y = obstacle.y;
      }
      else if ((obstacle.y > queen.y) && (obstacle.y < obstacleN.y))
      {
        obstacleN.y = obstacle.y;
      }
    }
    else if ((queen.y - obstacle.y) == (queen.x - obstacle.x))
    { // obstacle lies on the diagonal-forward line of attack ("/")
      if ((obstacle.y < queen.y) && (obstacle.y > obstacleSW.y))
      {
        obstacleSW.y = obstacle.y;
        obstacleSW.x = obstacle.x;
      }
      else if ((obstacle.y > queen.y) && (obstacle.y < obstacleNE.y))
      {
        obstacleNE.y = obstacle.y;
        obstacleNE.x = obstacle.x;
      }
    }
    else if ((queen.y - obstacle.y) == -(queen.x - obstacle.x))
    { // obstacle lies on the diagonal-backward line of attack ("\")
      if ((obstacle.y < queen.y) && (obstacle.y > obstacleSE.y))
      {
        obstacleSE.y = obstacle.y;
        obstacleSE.x = obstacle.x;
      }
      else if ((obstacle.y > queen.y) && (obstacle.y < obstacleNW.y))
      {
        obstacleNW.y = obstacle.y;
        obstacleNW.x = obstacle.x;
      }
    }

  }

  // Calculates the total number of attacked fields:
  int attackedFields = 0;
  attackedFields += ((obstacleNW.y - 1) - queen.y);
  attackedFields += ((obstacleN.y - 1) - queen.y);
  attackedFields += ((obstacleNE.y - 1) - queen.y);
  attackedFields += ((obstacleE.x - 1) - queen.x);
  attackedFields += (queen.x - (obstacleW.x + 1));
  attackedFields += (queen.y - (obstacleSE.y + 1));
  attackedFields += (queen.y - (obstacleS.y + 1));
  attackedFields += (queen.y - (obstacleSW.y + 1));

  std::cout << attackedFields << std::endl;

  return 0;
}
