/*
Solution to the "CountLuck" challenge by HackerRank:
https://www.hackerrank.com/challenges/count-luck
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <queue>

struct Position
{
  int N;
  int M;
  char arrivalFrom;
  int totalCrossroads;
};

const char PATH = '.';
const char WALKED_PATH = ',';
const char TREE = 'X';
const char TARGET = '*';
const char PLAYER = 'M';

std::vector<std::vector<char>> map;
std::vector<char> currentPath;

std::queue<Position> positionsToEvaluate;

int playerN, playerM; // denotes current walker's position
int targetN, targetM; // denotes the target's position
int crossroadsCount;
bool found;

void print_map()
{
  for (int n = 0; n < map.size(); ++n)
  {
    for (int m = 0; m < map[n].size(); ++m)
    {
      std::cout << map[n][m];
    }
    std::cout << std::endl;
  }
}

void step_towards_target_with_backtracking()
{
  Position analyzedPosition = positionsToEvaluate.front();
  positionsToEvaluate.pop();
  Position nextPosition;

  int n = analyzedPosition.N;
  int m = analyzedPosition.M;

/*
  std::cout << "Analyzed position: (" << n << ", " << m << ")" << std::endl
            << "totalCrossroads: " << analyzedPosition.totalCrossroads << std::endl
            << "arrived from: " << analyzedPosition.arrivalFrom << std::endl;
*/

  int pathsCount = 0;
  bool canGoN = false, canGoE = false, canGoW = false, canGoS = false;

  // order of traversal: N, E, W, S
  if ((targetN == n) && (targetM == m))
  {
    // std::cout << "step_(...)_backtracking(): returning " << analyzedPosition.totalCrossroads << std::endl;
    crossroadsCount = analyzedPosition.totalCrossroads;
    std::queue<Position> empty;
    std::swap(positionsToEvaluate, empty);
    return;
  }

  if ((map[n - 1][m] == PATH) && (analyzedPosition.arrivalFrom != 'N'))
  {
    ++pathsCount;
    canGoN = true;
  }
  if ((map[n][m + 1] == PATH) && (analyzedPosition.arrivalFrom != 'E'))
  {
    ++pathsCount;
    canGoE = true;
  }
  if ((map[n][m - 1] == PATH) && (analyzedPosition.arrivalFrom != 'W'))
  {
    ++pathsCount;
    canGoW = true;
  }
  if ((map[n + 1][m] == PATH) && (analyzedPosition.arrivalFrom != 'S'))
  {
    ++pathsCount;
    canGoS = true;
  }

  int isThisCrossroad = (pathsCount > 1 ? 1 : 0);

  if (isThisCrossroad)
  {
    // std::cout << "(" << n << ", " << m << ") is a crossroad!" << std::endl;
  }

  if (canGoN)
  {
    nextPosition.N = n - 1;
    nextPosition.M = m;
    nextPosition.arrivalFrom = 'S';
    nextPosition.totalCrossroads = analyzedPosition.totalCrossroads + isThisCrossroad;
    positionsToEvaluate.push(nextPosition);
  }
  if (canGoE)
  {
    nextPosition.N = n;
    nextPosition.M = m + 1;
    nextPosition.arrivalFrom = 'W';
    nextPosition.totalCrossroads = analyzedPosition.totalCrossroads + isThisCrossroad;
    positionsToEvaluate.push(nextPosition);
  }
  if (canGoW)
  {
    nextPosition.N = n;
    nextPosition.M = m - 1;
    nextPosition.arrivalFrom = 'E';
    nextPosition.totalCrossroads = analyzedPosition.totalCrossroads + isThisCrossroad;
    positionsToEvaluate.push(nextPosition);
  }
  if (canGoS)
  {
    nextPosition.N = n + 1;
    nextPosition.M = m;
    nextPosition.arrivalFrom = 'N';
    nextPosition.totalCrossroads = analyzedPosition.totalCrossroads + isThisCrossroad;
    positionsToEvaluate.push(nextPosition);
  }

}

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for (int t = 0; t < T; ++t)
  {
    map.clear();
    currentPath.clear();

    int N, M, K;
    std::cin >> N >> M;

    // Prepares an empty map and frames it with the trees:
    map.resize(N + 2);
    for (int n = 0; n < N + 2; ++n)
    {
      map[n].resize(M + 2);
    }
    for (int n = 0; n < N + 2; ++n)
    {
      map[n][0] = TREE;
      map[n][M + 1] = TREE;
    }
    for (int m = 0; m < M + 2; ++m)
    {
      map[0][m] = TREE;
      map[N + 1][m] = TREE;
    }

    // Reads the map contents from the standard input:
    for (int n = 1; n <= N; ++n)
    {
      for (int m = 1; m <= M; ++m)
      {
        std::cin >> map[n][m];

        // substitutes the target with a path (simplifies processing):
        if (TARGET == map[n][m])
        {
          map[n][m] = PATH;
          targetN = n;
          targetM = m;
        }

        // remembers player's initial position:
        else if (PLAYER == map[n][m])
        {
          playerN = n;
          playerM = m;
        }
      }
    }

    // print_map();

    std::cin >> K;

    // clears the queue and emplaces the first element:
    std::queue<Position> empty;
    std::swap(positionsToEvaluate, empty);

    found = false;
    crossroadsCount = -1;

    Position firstPosition;
    firstPosition.N = playerN;
    firstPosition.M = playerM;
    firstPosition.arrivalFrom = 'U';
    firstPosition.totalCrossroads = 0;
    positionsToEvaluate.push(firstPosition);

    while ((positionsToEvaluate.size() > 0) && (!found))
      step_towards_target_with_backtracking();

    // std::cout << crossroadsCount << std::endl;

    std::cout << (K == crossroadsCount ? "Impressed" : "Oops!") << std::endl;
  }

  return 0;
}
