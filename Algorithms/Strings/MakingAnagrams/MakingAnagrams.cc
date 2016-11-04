/*
Solution to the "MakeItAnagram" challenge by HackerRank:
https://www.hackerrank.com/challenges/make-it-anagram
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>
#include <cmath>

const int CHARS = 256;

int main(int argc, char **argv)
{
  std::string a, b;
  std::cin >> a >> b;

  int histogramA[CHARS], histogramB[CHARS];

  // initializes the histogram cells to 0:
  for(int c = 0; c < CHARS; ++c)
  {
    histogramA[c] = histogramB[c] = 0;
  }

  // fills in the histograms for both strings:
  for(int c = 0; c < a.length(); ++c)
  {
    ++histogramA[a[c]];
  }
  for(int c = 0; c < b.length(); ++c)
  {
    ++histogramB[b[c]];
  }

  // calculates the total difference between both histograms -
  // this is an answer to the problem:
  int deletions = 0;
  for(int c = 0; c < CHARS; ++c)
  {
    deletions += std::abs(histogramA[c] - histogramB[c]);
  }

  std::cout << deletions << std::endl;

  return 0;
}
