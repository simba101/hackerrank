/*
Solution to the "FlatlandSpaceStations" challenge by HackerRank:
https://www.hackerrank.com/challenges/flatland-space-stations
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
  int N, M;
  int maxDist = 0;

  std::cin >> N >> M;
  std::vector<int> stations;
  stations.resize(M);
  for(int m = 0; m < M; ++m)
  {
    std::cin >> stations[m];
  }
  std::sort(stations.begin(), stations.end());

  // outputs debug info:
  /*
  std::cout << N << " crties, " << M << " space stations:" << std::endl;
  for(int m = 0; m < M; ++m)
  {
    std::cout << stations[m] << "\t";
  }
  std::cout << std::endl;
  */

  // takes into account the rest of the chain:
  for(int m = 1; m < M; ++m)
  {
    int chainLength = (stations[m] - stations[m - 1]) - 1;
    int chainDist = (chainLength + 1) / 2;
    if(chainDist > maxDist)
    {
      maxDist = chainDist;
    }
  }

  // takes into account the first part of the chain:
  int distBegin = stations[0];
  if(distBegin > maxDist)
  {
    maxDist = distBegin;
  }

  // takes into account the last part of the chain:
  int distEnd = (N - 1) - stations[M - 1];
  if(distEnd > maxDist)
  {
    maxDist = distEnd;
  }

  std::cout << maxDist << std::endl;

  return 0;
}
