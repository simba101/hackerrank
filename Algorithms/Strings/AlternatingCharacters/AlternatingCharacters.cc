/*
Solution to the "AlternatingCharacters" challenge by HackerRank:
https://www.hackerrank.com/challenges/alternating-characters
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    std::string line; // will contain only 'A' and 'B' characters.
    std::cin >> line;

    int deletions = 0;
    char lastChar = line[0];

    for(int pos = 1; pos < line.length(); ++pos)
    {
      if(line[pos] == lastChar)
      {
        // this char needs to be deleted:
        ++deletions;
      }
      else
      {
        lastChar = line[pos];
      }
    }

    std::cout << deletions << std::endl;
  }

  return 0;
}
