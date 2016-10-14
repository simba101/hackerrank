/*
Solution to the "MinimumDistances" challenge by HackerRank:
https://www.hackerrank.com/challenges/minimum-distances
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <map>

int main(int argc, char **argv)
{
  constexpr int MAXLEN = 1000; // maximum value of N

  int N;
  std::cin >> N;
  int number;

  std::map<int, int> distances;
  int minimumDistance = MAXLEN + 1;

  for(int n = 0; n < N; ++n)
  {
    std::cin >> number;

    // If the number is already in array, calculates the distance
    // between this and previous element:
    if(distances.find(number) != distances.end())
    {
      int dist = n - (distances.find(number))->second;
      if(dist < minimumDistance)
      {
        minimumDistance = dist;
      }
    }

    // Otherwise, current number's position is remembered:
    else
    {
      distances[number] = n;
    }
  }

  std::cout << (minimumDistance == MAXLEN + 1 ? -1 : minimumDistance) << std::endl;

  return 0;
}
