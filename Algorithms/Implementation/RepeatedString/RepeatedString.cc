/*
Solution to the "RepeatedString" challenge by HackerRank:
https://www.hackerrank.com/challenges/repeated-string
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  std::string s;
  std::cin >> s;
  unsigned long long int c;
  std::cin >> c;

  int as_in_string = 0;
  for(int i = 0; i < s.length(); ++i)
  {
    if('a' == s[i])
    {
      ++as_in_string;
    }
  }

  unsigned long long int full_repeats = c / s.length();
  int remainder = c - (full_repeats * s.length());

  int as_in_remainder = 0;
  for(int i = 0; i < remainder; ++i)
  {
    if('a' == s[i])
    {
      ++as_in_remainder;
    }
  }

  unsigned long long int total_as = (full_repeats * as_in_string) + as_in_remainder;

  std::cout << total_as << std::endl;


  return 0;
}
