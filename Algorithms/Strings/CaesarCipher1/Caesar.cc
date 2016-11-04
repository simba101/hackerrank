/*
Solution to the "Caesar Cipher" challenge by HackerRank:
https://www.hackerrank.com/challenges/caesar-cipher-1
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

const int NLIMIT = 100;
const int RANGE = 'Z' - 'A' + 1;

char pt[NLIMIT + 1], ct[NLIMIT + 1];

int main(int argc, char **argv)
{
  int buflen;
  int shift;

  std::cin >> buflen;
  std::cin >> pt;
  std::cin >> shift;

  for(int i = 0; i < buflen; ++i)
  {
    if(pt[i] >= 'A' && pt[i] <= 'Z')
    {
      int letter = pt[i] - 'A';
      letter += shift;
      letter = letter % RANGE;
      letter += 'A';
      ct[i] = static_cast<char>(letter);
    }
    else if(pt[i] >= 'a' && pt[i] <= 'z')
    {
      int letter = pt[i] - 'a';
      letter += shift;
      letter %= RANGE;
      letter += 'a';
      ct[i] = static_cast<char>(letter);
    }
    else
    {
      ct[i] = pt[i];
    }
  }
  ct[buflen] = '\0';

  std::cout << ct << std::endl;

  return 0;
}
