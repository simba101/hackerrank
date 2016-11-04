/*
Solution to the "GemStones" challenge by HackerRank:
https://www.hackerrank.com/challenges/gem-stones
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

const int LETTERS = 'z' - 'a' + 1;

int main(int argc, char **argv)
{
  int N;
  std::cin >> N;

  bool isGem[LETTERS];
  for(int g = 0; g < LETTERS; ++g)
  {
    isGem[g] = true;
  }

  for(int n = 0; n < N; ++n)
  {
    bool contains[LETTERS];
    for(int k = 0; k < LETTERS; ++k)
    {
      contains[k] = false;
    }

    std::string stone;
    std::cin >> stone;
    for(int c = 0; c < stone.length(); ++c)
    {
      contains[stone[c] - 'a'] = true;
    }

    for(int g = 0; g < LETTERS; ++g)
    {
      isGem[g] = isGem[g] && contains[g];
    }
  }

  int gems = 0;
  for(int g = 0; g < LETTERS; ++g)
  {
    if(isGem[g])
    {
      ++gems;
    }
  }

  std::cout << gems << std::endl;

  return 0;
}
