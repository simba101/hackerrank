/*
Solution to the "TwoStrings" challenge by HackerRank:
https://www.hackerrank.com/challenges/two-strings
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

const int LETTERS = 'Z' - 'A' + 1;

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  std::string stringA, stringB;

  bool histogramA[LETTERS], histogramB[LETTERS];

  for(int t = 0; t < T; ++t)
  {
    std::cin >> stringA >> stringB;

    // clears the histograms:
    for(int l = 0; l < LETTERS; ++l)
    {
      histogramA[l] = false;
      histogramB[l] = false;
    }

    // creates a histogram for A:
    for(int l = 0; l < stringA.length(); ++l)
    {
      histogramA[stringA[l] - 'a'] = true;
    }

    // creates a histogram for B:
    for(int l = 0; l < stringB.length(); ++l)
    {
      histogramB[stringB[l] - 'a'] = true;
    }

    // if there is at least one same letter present in both strings,
    // then there is a common substring among these two strings.
    bool isCommonSubstring = false;
    for(int l = 0; ((l < LETTERS) && (!isCommonSubstring)); ++l)
    {
      if(histogramA[l] && histogramB[l])
      {
        isCommonSubstring = true;
      }
    }

    std::cout << (isCommonSubstring ? "YES" : "NO") << std::endl;
  }

  return 0;
}
