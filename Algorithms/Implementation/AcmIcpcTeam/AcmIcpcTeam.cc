/*
Solution to the "AcmIcpcTeam" challenge by HackerRank:
https://www.hackerrank.com/challenges/acm-icpc-team
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char **argv)
{
  int people, topics;
  std::cin >> people >> topics;
  std::vector<std::vector<bool>> group;

  group.resize(people);
  for(int p = 0; p < people; ++p)
  {
    group[p].resize(topics);
    std::string line;
    std::cin >> line;
    for(int t = 0; t < topics; ++t)
    {
      group[p][t] = ('1' == line[t]);
    }

  }

  // for p-numbered group of people, the number of 2-person teams possible
  // is n(n - 3) / 2
  int knownTopics;
  int maxKnownTopics = 0;
  int maxedTeamsCount = 0;

  for(int p = 0; p < people - 1; ++p)
  {
    for(int q = p + 1; q < people; ++q)
    {
      // calculate the number of topics known by p or q:
      knownTopics = 0;
      for(int t = 0; t < topics; ++t)
      {
        if((true == group[p][t]) | (true == group[q][t]))
        {
          knownTopics += 1;
        }
      }
      if(knownTopics > maxKnownTopics)
      {
        maxKnownTopics = knownTopics;
        maxedTeamsCount = 1;
      }
      else if(knownTopics == maxKnownTopics)
      {
        maxedTeamsCount += 1;
      }

    }
  }

  std::cout << maxKnownTopics << std::endl << maxedTeamsCount << std::endl;


  return 0;
}
