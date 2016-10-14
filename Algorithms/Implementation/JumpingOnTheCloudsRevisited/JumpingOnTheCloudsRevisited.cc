/*
Solution to the "JumpingOnTheCloudsRevisited" challenge by HackerRank:
https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  int N, K;
  std::cin >> N >> K;
  std::vector<int> clouds;
  clouds.resize(N);

  for(int n = 0; n < N; ++n)
  {
    std::cin >> clouds[n];
  }

  int pos = 0;
  int energy = 100;

  do
  {
    pos += K;
    pos %= N;
    energy -= 1;

    // Additional energy penalty (-2) for landing on a thundercloud:
    if(1 == clouds[pos])
    {
      energy -= 2;
    }
  }
  while(pos != 0);

  std::cout << energy << std::endl;

  return 0;
}
