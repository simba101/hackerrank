/*
Solution to the "JumpingOnTheClouds" challenge by HackerRank:
https://www.hackerrank.com/challenges/jumping-on-the-clouds
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  int N;
  std::cin >> N;
  std::vector<int> clouds;
  clouds.resize(N);
  
  for(int n = 0; n < N; ++n)
  {
    std::cin >> clouds[n];
  }

  int pos = 0;
  int moves = 0;
  
  while(pos < N - 1)
  {
    // 1 denotes a thundercloud.
    if(1 == clouds[pos + 2])
    {
      pos += 1;
    }
    else
    {
      pos += 2;
    }

    moves += 1;
  }

  std::cout << moves << std::endl;

  return 0;
}
