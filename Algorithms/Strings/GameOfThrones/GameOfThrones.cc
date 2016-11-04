/*
Solution to the "GameOfThrones" challenge by HackerRank:
https://www.hackerrank.com/challenges/game-of-thrones
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

const int CHARS = 256;

int main(int argc, char **argv)
{
  int histogram[CHARS];

  std::string input;
  std::cin >> input;

  // initializes the histogram values to 0:
  for(int letter = 0; letter < CHARS; ++letter)
  {
    histogram[letter] = 0;
  }

  // generates the letters' histogram:
  for(int letter = 0; letter < input.length(); ++letter)
  {
    ++histogram[input[letter]];
  }

  // calculates the number of distinct letters of odd count:
  int oddLetters = 0;
  for(int letter = 0; letter < CHARS; ++letter)
  {
    if(histogram[letter] % 2 != 0)
    {
      ++oddLetters;
    }
  }

  // a string may be shuffled to become a palindrome if and only if
  // it has no more than one group of letters of odd count.
  std::cout << (oddLetters < 2 ? "YES" : "NO") << std::endl;

  return 0;
}
