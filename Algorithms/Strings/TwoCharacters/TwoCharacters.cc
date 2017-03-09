/*
Solution to the "TwoCharacters" challenge by HackerRank:
https://www.hackerrank.com/challenges/two-characters
Written on 08-03-2017 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <cmath>

const int BUF_SIZE = 10e5 + 3;

int main(int argc, char **argv)
{
  int length;
  std::cin >> length;
  static char buffer[BUF_SIZE];
  std::cin >> buffer;

  // Let's brute-force through this problem. For a string containing all the
  // possible 26 characters this means checking (26 choose 2) == 325 cases.

  // First let's check how many times a given letter appears in a string:
  const int LETTERS = 'z' - 'a' + 1;
  int histogram[LETTERS];
  for (int i = 0; i < LETTERS; ++i)
  {
    // Clears the histogram:
    histogram[i] = 0;
  }
  int ptr = 0;
  while (buffer[ptr] != '\0')
  {
    histogram[buffer[ptr] - 'a'] += 1;
    ptr += 1;
  }

  // The maximum recorded length of a t-string so far:
  int max_length = 0;

  // Checks every pair of letters that MAY result in a valid t-string:
  for (char first = 'a'; first <= 'z'; ++first)
  {
    for (char second = first + 1; second <= 'z'; ++second)
    {
      if (
        // both letters have to exist in the string:
        (histogram[first - 'a'] * histogram[second - 'a'] > 0) &&
        // and their frequencies must differ by at most one:
        (std::abs(histogram[first - 'a'] - histogram[second - 'a']) < 2)
      )
      {
        // Checks whether these letters form a valid t-string:
        int ptr = 0;
        char last = '0'; // guaranteed to be different than two analyzed chars.

        // Analyzes only the candidates that WILL result in a longer T-string:
        bool isValidTString =
            ((histogram[first - 'a'] + histogram[second - 'a']) > max_length);
        while ((isValidTString) && (buffer[ptr] != '\0'))
        {
          if ((buffer[ptr] == first) || (buffer[ptr] == second))
          {
            isValidTString = (buffer[ptr] != last);
            last = buffer[ptr];
          }
          ptr += 1;
        }

        if (isValidTString)
        {
          max_length = histogram[first - 'a'] + histogram[second - 'a'];
        }
      }
    }
  }

  std::cout << max_length << std::endl;

  return 0;
}
