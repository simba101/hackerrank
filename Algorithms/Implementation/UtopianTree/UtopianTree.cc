/*
Solution to the "UtopainTree" challenge by HackerRank:
https://www.hackerrank.com/challenges/utopian-tree
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;
  for(int t = 0; t < T; ++t)
  {
    unsigned long long height = 1;
    int noOfCycles;
    std::cin >> noOfCycles;

    int fullCycles = noOfCycles / 2;

    for(int fc = 0; fc < fullCycles; ++fc)
    {
      height *= 2ULL;
      height += 1ULL;
    }

    if(noOfCycles % 2 == 1)
    {
      height *= 2ULL;
    }

    std::cout << height << std::endl;
  }

  return 0;
}
