/*
Solution to the "HackerlandRadioTransmitters" challenge by HackerRank:
https://www.hackerrank.com/challenges/hackerland-radio-transmitters
Written on 06-12-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <vector>
#include <algorithm>


int main(int argc, char **argv)
{
  // Gathers the data:
  int housesCount, transmitterRadius;
  std::cin >> housesCount >> transmitterRadius;
  std::vector<int> locations(housesCount); // stores the locations of houses.
  for (int h = 0; h < housesCount; ++h)
  {
    std::cin >> locations[h];
  }

  // Sorts the vector of houses' locations in nondescending order:
  std::sort(locations.begin(), locations.end());

  // Houses with addresses up to this number have been covered by transmitters:
  int covered = -1;
  int transmittersCount = 0;

  // Going bottom-up, puts* transmitters on the houses
  // until the last one is covered as well.
  // *) not really. Think of it as a "virtual" transmitters :)
  while(covered < housesCount - 1)
  {
		// Finds the next house that needs to be covered:
		int nextHouse = covered + 1;

    // The optimal place to put a transmitter will be [transmitterRadius]
    // blocks to the right - so that this house is still reached:
		// int optimalTransmitterLocation =
	  //   locations[nextHouse] + transmitterRadius;

    // But it is possible that there is no house to put the transmitter on
    // in the suggested location. Therefore, a right-most house located at most
    // [transmitterRadius] units to the right of [nextHouse] needs to be found.
    int optimalTransmitterHouse = nextHouse + 1;
    while((locations[optimalTransmitterHouse] -
        locations[nextHouse] <= transmitterRadius) &&
        (optimalTransmitterHouse < housesCount))
    {
      optimalTransmitterHouse += 1;
    }

    // The loop above terminates on the first house outside the required range.
    // Goes one house back to stay in the required range.
    optimalTransmitterHouse -= 1;

    // A transmitter should be put on this house.
    transmittersCount += 1;

    // If a transmitter is put on the [optimalTransmitterHouse], all the houses
    // up to the [optimalTransmitterHouse's location + transmitterRadius] are
    // within the reach of a radio network. Finds the index of the right-most
    // house still within the reach of a transmitter:
    int reached = optimalTransmitterHouse;
    while((locations[reached] - locations[optimalTransmitterHouse] <=
        transmitterRadius) && (reached < housesCount))
    {
      reached += 1;
    }
    reached -= 1; // for same reasons as above :)
    covered = reached;
  }

  std::cout << transmittersCount << std::endl;

  return 0;
}
