/*
Solution to the "Euler004" challenge by HackerRank:
https://www.hackerrank.com/contests/projecteuler/challenges/euler004
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N;
    std::cin >> N;

    int biggest_palindrome = 0;

    for(int i = 100; i < 1000; ++i)
    {
      for(int j = 101101 / i; j < 1000; ++j)
      {
        int palindrome_candidate = i * j;
        if(
            (palindrome_candidate < N) &&
            (palindrome_candidate % 11 == 0) &&
            (palindrome_candidate > biggest_palindrome)
        )
        {
          std::string text = std::to_string(palindrome_candidate);
          std::string reversed = text;
          std::reverse(reversed.begin(), reversed.end());
          if(text == reversed)
          {
            if(palindrome_candidate > biggest_palindrome)
            {
              biggest_palindrome = palindrome_candidate;
            }
          }
        }
      }
    }

    std::cout << biggest_palindrome << std::endl;
  }

  return 0;
}
