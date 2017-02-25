/*
Solution to the "JourneyToTheMoon" challenge by HackerRank:
https://www.hackerrank.com/challenges/journey-to-the-moon
Written on 25-02-2017 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <vector>


struct Group
{
  int code;
  int size;
};


int main(int argc, char **argv)
{
  int N; // Holds the number of the astronauts available for the mission.
  int P; // Holds the number of pairs indicating that two elements
         // (a.k.a. astronauts) are in the same group (a.k.a. country).

  // Loads the number of astronauts and the number of pairs between them:
  std::cin >> N >> P;

  std::vector<Group> groups(N);

  // In the beginning every pilot is assumed to come from a distinct country:
  for (int i = 0; i < N; ++i)
  {
    groups[i].code = i;
    groups[i].size = 1;
  }

  // Loads and processes links between the pilots one by one:
  for (int p = 0; p < P; ++p)
  {
    int a, b;
    std::cin >> a >> b;

    // The algorithm does not merge the individual people, but their groups
    // together. The roots of each group need to be merged.
    int rootA = a;
    while (groups[rootA].code != rootA)
    {
      rootA = groups[rootA].code;
    }

    int rootB = b;
    while (groups[rootB].code != rootB)
    {
      rootB = groups[rootB].code;
    }

    int lower = (rootA < rootB) ? rootA : rootB;
    int upper = (rootA > rootB) ? rootA : rootB;
    if (lower != upper)
    {
      // OK, merges the groups:
      groups[lower].size += groups[upper].size;
      groups[upper].size = 0;
      groups[upper].code = groups[lower].code;
    }
    else
    {
      // The groups are already merged, no need to do anything.
      // (this would introduce a cycle to the merged group,
      // which is otherwise a nice tree)
    }
  }

  // Right now every entry in a [groups] vector having size greater than 0
  // denotes a distinct country and its size is the total number of pilots
  // available for picking.
  // The answer to this question involves calculating how many disjoint pairs
  // (a.k.a. pairs where the two elements are from disjoint sets) exist.
  // And the formula for that is (N^2 - sum(sizes_of_disjoint_sets^2)).

  // Calculates the answer:
  long long int sum_of_squared_sizes_of_disjoint_sets = 0LL;
  for (int i = 0; i < N; ++i)
  {
    if (groups[i].size > 0)
    {
      sum_of_squared_sizes_of_disjoint_sets +=
          static_cast<long long int>( (groups[i].size * groups[i].size) );
    }
  }

  // That damn testcases with answers not fitting in signed 32 bits
  // caused this otherwise pretty solution to involve static casting :-(
  long long int longN = static_cast<long long int>(N);
  long long int ans =
      ((longN * longN) - sum_of_squared_sizes_of_disjoint_sets) / 2LL;
  std::cout << ans << std::endl;

  return 0;
}
