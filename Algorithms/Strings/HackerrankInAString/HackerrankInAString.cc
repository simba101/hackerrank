/*
Solution to the "HackerrankInAString" challenge by HackerRank:
https://www.hackerrank.com/challenges/hackerrank-in-a-string
Written on 17-03-2017 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <string>

const std::string hr = "hackerrank";

int main(int argc, char **argv)
{
  // First line of input contains an int T - number of queries; 2 <= T <= 200
  int T;
  std::cin >> T;

  for (int t = 0; t < T; ++t)
  {
    // Each query is in form of a string.
    // The program has to print YES or NO depending on whether the string
    // contains a subsequence "hackerrank".

    std::string query;
    std::cin >> query;

    int hrptr = 0;
    int qptr = 0;

    while ((hrptr < hr.size()) && (qptr < query.size()))
    {
      if (query[qptr] == hr[hrptr])
      {
        hrptr += 1;
      }

      qptr += 1;
    }

    std::cout << (hrptr == hr.size() ? "YES" : "NO") << std::endl;


  }

  return 0;
}
