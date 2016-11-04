/*
Solution to the "SherlockAndAnagrams" challenge by HackerRank:
https://www.hackerrank.com/challenges/sherlock-and-anagrams
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

const int LETTERS_COUNT = 'z' - 'a' + 1;

std::string input;

bool isAnagram(int startA, int startB, int length)
{
  int histA[26] = {0};
  int histB[26] = {0};

  // Generates the histograms:
  for(int pos = startA; pos < startA + length; ++pos)
  {
    ++histA[input[pos] - 'a'];
  }
  for(int pos = startB; pos < startB + length; ++pos)
  {
    ++histB[input[pos] - 'a'];
  }

  for(int letter = 0; letter < LETTERS_COUNT; ++letter)
  {
    if(histA[letter] != histB[letter])
    {
      return false;
    }
  }
  return true;
}

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    char sub1[100] = {0};
    char sub2[100] = {0};

    std::cin >> input;

    int count = 0;
    for(int l = 1; l < input.length(); ++l)
    {
      for(int i = 0; i < input.length() - l; ++i)
      {
        for(int j = i + 1; j < input.length() - l + 1; ++j)
        {
          if(isAnagram(i, j, l))
          {
            ++count;
          }
        }
      }
    }

    std::cout << count << std::endl;
  }

  return 0;
}
