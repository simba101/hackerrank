/*
Solution to the "ConnectedCellsInAGrid" challenge by HackerRank:
https://www.hackerrank.com/challenges/connected-cell-in-a-grid
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>

const int BORDER_CODE = -9;
const int USED_CODE = -1;
const int WATER_CODE = 0;
const int ISLAND_CODE = 1;

std::vector<std::vector<int>> map;

void printMap()
{
  for (int m = 0; m < map.size(); ++m)
  {
    for (int n = 0; n < map[m].size(); ++n)
    {
      std::cout << map[m][n] << "\t";
    }
    std::cout << std::endl;
  }
}

void getIslandArea(int m, int n, int &currentArea)
{
  currentArea += 1;
  map[m][n] = USED_CODE;
  if (map[m - 1][n - 1] == ISLAND_CODE)
  {
    getIslandArea(m - 1, n - 1, currentArea);
  }
  if (map[m - 1][n] == ISLAND_CODE)
  {
    getIslandArea(m - 1, n, currentArea);
  }
  if (map[m - 1][n + 1] == ISLAND_CODE)
  {
    getIslandArea(m - 1, n + 1, currentArea);
  }
  if (map[m][n - 1] == ISLAND_CODE)
  {
    getIslandArea(m, n - 1, currentArea);
  }
  if (map[m][n + 1] == ISLAND_CODE)
  {
    getIslandArea(m, n + 1, currentArea);
  }
  if (map[m + 1][n - 1] == ISLAND_CODE)
  {
    getIslandArea(m + 1, n - 1, currentArea);
  }
  if (map[m + 1][n] == ISLAND_CODE)
  {
    getIslandArea(m + 1, n, currentArea);
  }
  if (map[m + 1][n + 1] == ISLAND_CODE)
  {
    getIslandArea(m + 1, n + 1, currentArea);
  }
}

int main(int argc, char **argv)
{
  int N, M;
  std::cin >> M >> N;

  int maxArea = 0, currArea;

  // Reserves the map, fills it with zeroes, adds safe-border:
  map.resize(M + 2);
  for (int m = 0; m < M + 2; ++m)
  {
    map[m].resize(N + 2);
  }
  for (int m = 0; m < M + 2; ++m)
  {
    map[m][0] = BORDER_CODE;
    map[m][N + 1] = BORDER_CODE;
  }
  for (int n = 0; n < N + 2; ++n)
  {
    map[0][n] = BORDER_CODE;
    map[M + 1][n] = BORDER_CODE;
  }

  // reads the map from the standard input:
  for (int m = 1; m <= M; ++m)
  {
    for (int n = 1; n <= N; ++n)
    {
      std::cin >> map[m][n];
    }
  }

  // printMap();

  // Flood-fills the islands, keeping track of the one with the largest area:
  for (int m = 1; m <= M; ++m)
  {
    for (int n = 1; n <= N; ++n)
    {
      if (map[m][n] == ISLAND_CODE)
      {
        currArea = 0;
        getIslandArea(m, n, currArea);

        if (currArea > maxArea)
        {
          maxArea = currArea;
        }
        // std::cout << "getIslandArea(" << m << ", " << n << ") == " << currArea << std::endl;
      }
    }
  }

  std::cout << maxArea << std::endl;

  return 0;
}
