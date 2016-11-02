/*
Solution to the "FairRations" challenge by HackerRank:
https://www.hackerrank.com/challenges/fair-rations
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  int N;
  std::cin >> N;

  int sum = 0;
  std::vector<int> loaves;
  loaves.resize(N);

  for(int n = 0; n < N; ++n)
  {
    std::cin >> loaves[n];
    sum += loaves[n];
  }

  if(sum % 2 == 1)
  {
    std::cout << "NO" << std::endl;
  }
  else
  {
    int giveawayBreadCount = 0;
    for(int human = 0; human < N; ++human)
    {
      if(loaves[human] % 2 != 0)
      {
        loaves[human] += 1;
        loaves[human + 1] += 1;
        giveawayBreadCount += 2;
      }
    }

    std::cout << giveawayBreadCount << std::endl;
  }

  return 0;
}
