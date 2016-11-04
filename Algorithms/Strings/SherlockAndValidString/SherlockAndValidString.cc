/*
Solution to the "SherlockAndValidString" challenge by HackerRank:
https://www.hackerrank.com/challenges/sherlock-and-valid-string
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

const int LETTERS = 'z' - 'a' + 1;

int main(int argc, char **argv)
{
  std::string input;
  int histogram[LETTERS] = {0};

  std::cin >> input;

  // Generates the histogram:
  for (int l = 0; l < input.length(); ++l)
  {
    ++histogram[input[l] - 'a'];
  }

  // Adds non-zero histogram values to the vector:
  std::vector<int> frequencies;
  for (int v = 0; v < LETTERS; ++v)
  {
    if (histogram[v] > 0)
    {
      frequencies.push_back(histogram[v]);
    }
  }

  // In the initial state the program knows nothing about this string's validity
  // so it assumes the following values:
  bool isValid = true;
  bool canBeMadeValid = false;

  // Determines whether this string is actually already valid:
  for (int i = 1; ((i < frequencies.size()) && isValid); ++i)
  {
    if (frequencies.at(i) != frequencies.at(0))
    {
      isValid = false;
    }
  }

  if(!isValid)
  {
    // Determines whether this string may actually be made valid:
    for (int i = 0; ((i < frequencies.size()) && (!canBeMadeValid)); ++i)
    {
      // Constructs a new frequencies vector with i'th frequency decreased by one:
      std::vector<int> newfreq;
      for (int k = 0; k < frequencies.size(); ++k)
      {
        if (k == i)
        {
          int decreased = frequencies.at(k) - 1;
          if (decreased > 0)
          {
            newfreq.push_back(decreased);
          }
        }
        else
        {
          newfreq.push_back(frequencies.at(k));
        }
      }


      // Checks whether such a new string is valid:
      bool isNewStringValid = true;
      for (int nf = 1; nf < newfreq.size(); ++nf)
      {
        if (newfreq.at(nf) != newfreq.at(0))
        {
          isNewStringValid = false;
        }
      }

      canBeMadeValid = isNewStringValid;
    }
  }

  std::cout << ( (isValid || canBeMadeValid) ? "YES" : "NO" ) << std::endl;

  return 0;
}
