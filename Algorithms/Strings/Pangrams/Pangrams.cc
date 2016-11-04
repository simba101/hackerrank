/*
Solution to the "Pangrams" challenge by HackerRank:
https://www.hackerrank.com/challenges/pangrams
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

const int LETTERS = 'Z' - 'A' + 1;

int main(int argc, char **argv)
{
  std::string input;
  std::getline(std::cin, input);
  int histogram[LETTERS];
  for(int i = 0; i < LETTERS; ++i)
  {
    histogram[i] = 0;
  }

  for(auto &c : input)
  {
    c = toupper(c);
  }

  for(int i = 0; i < input.length(); ++i)
  {
    if(input[i] >= 'A' && input[i] <= 'Z')
    {
      ++histogram[input[i] - 'A'];
    }
  }

  bool isFullAlphabet = true;
  for(int i = 0; ((i < LETTERS) && (isFullAlphabet)); ++i)
  {
    if(histogram[i] == 0)
    {
      isFullAlphabet = false;
    }
  }

  std::cout << (isFullAlphabet ? "" : "not ") << "pangram" << std::endl;

  return 0;
}
