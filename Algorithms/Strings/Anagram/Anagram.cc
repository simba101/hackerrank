/*
Solution to the "Anagram" challenge by HackerRank:
https://www.hackerrank.com/challenges/anagram
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>
#include <cmath>

const int LETTERS = 'Z' - 'A' + 1;

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    std::string input;
    std::cin >> input;
    int L = input.length();

    if(L % 2 != 0)
    {
      std::cout << "-1" << std::endl;
    }
    else
    {
      int histogramA[LETTERS], histogramB[LETTERS];
      for(int i = 0; i < LETTERS; ++i)
      {
        histogramA[i] = histogramB[i] = 0;
      }
      for(int c = 0; c < L / 2; ++c)
      {
        ++histogramA[input[c] - 'a'];
        ++histogramB[input[L - 1 - c] - 'a'];
      }

      int totalDifference = 0;
      for(int i = 0; i < LETTERS; ++i)
      {
        totalDifference += std::abs(histogramA[i] - histogramB[i]);
      }

      std::cout << totalDifference / 2 << std::endl;
    }
  }

  return 0;
}
