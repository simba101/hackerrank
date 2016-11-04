/*
Solution to the "TheLoveLetterMystery" challenge by HackerRank:
https://www.hackerrank.com/challenges/the-love-letter-mystery
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>
#include <cmath>

//const int MAX_STRLEN = 10000 + 1;

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    std::string text;
    std::cin >> text;
    int L = text.length();
    unsigned long long degradations = 0;
    for(int i = 0; i < L / 2; ++i)
    {
      char x = text[i];
      char y = text[L - i - 1];
      degradations += std::abs(x - y);
    }

    std::cout << degradations << std::endl;
  }

  return 0;
}
