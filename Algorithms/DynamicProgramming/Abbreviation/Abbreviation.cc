/*
Solution to the "Abbreviation" challenge by HackerRank:
https://www.hackerrank.com/challenges/abbr
Written on 09-12-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


int LCSLength(std::string const &a, std::string const &b)
{
  // Creates and pre-initializes the LCS DP array:
  std::vector< std::vector< int > > arr;
  arr.resize(a.size() + 1);
  for(int i = 0; i <= a.size(); ++i)
  {
    arr[i].resize(b.size() + 1);
    arr[i][0] = 0;
  }
  for(int j = 1; j <= b.size(); ++j)
  {
    arr[0][j] = 0;
  }

  // Calculates the LCS in a bottom-up fashion:
  for(int i = 1; i <= a.size(); ++i)
  {
    for(int j = 1; j <= b.size(); ++j)
    {
      if(a[i-1] == b[j-1])
      {
        arr[i][j] = arr[i-1][j-1] + 1;
      }
      else
      {
        // arr[i][j] = max( arr[i][j-1], arr[i-1][j] ):
        arr[i][j] = (arr[i][j-1] > arr[i-1][j]) ? arr[i][j-1] : arr[i-1][j];
      }
    }
  }

  return arr[a.size()][b.size()];
}


bool is_abbreviatable(std::string const &a, std::string const &b)
{
  // Every testcase consists of the two strings, A and B.
  // Is it possible to make string A equal to string B by:
  // * Capitalizing zero or more lowercase letters in string A,
  // * Removing all the remaining lowercase letters in A?
  //
  // The idea is to check for two conditions:
  // * whether a string consisting of only upcase letters
  //   found in original string A is a subsequence of string B,
  // * and whether the string B is a subsequence of a string consisting of ALL
  //   the letters found in the original string A.
  // The answer is YES if the two conditions are met.

  // creates a string containing only uppercase letters found in string A:
  std::stringstream ssA;
  for(int i = 0; i < a.size(); ++i)
  {
    if(std::isupper(a[i]))
    {
      ssA << a[i];
    }
  }
  std::string solelyUpcaseA = ssA.str();

  if(LCSLength(solelyUpcaseA, b) != solelyUpcaseA.size())
  {
    return false;
  }

  // creates a copy of string A and transforms it to be entirely upper-case:
  std::string transformedA = a;
  for(auto &c : transformedA)
  {
    c = std::toupper(c);
  }

  if(LCSLength(transformedA, b) != b.size())
  {
    return false;
  }

  return true;
}


int main(int argc, char **argv)
{
  int T;
  std::string a, b;
  std::cin >> T;

  // A boolean flag is needed to store the result of conditions checks.
  bool isGood;

  for (int t = 0; t < T; ++t)
  {
    std::cin >> a >> b;

    std::cout << (is_abbreviatable(a, b) ? "YES" : "NO") << std::endl;;
  }

  return 0;
}
