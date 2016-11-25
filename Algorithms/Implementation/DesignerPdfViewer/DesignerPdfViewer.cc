/*
Solution to the "DesignerPdfViewer" challenge by HackerRank:
https://www.hackerrank.com/challenges/designer-pdf-viewer
Written on 24-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>


const int LETTERS_COUNT = 26; // letters count in English alphabet

int main(int argc, char **argv)
{
  int heights[LETTERS_COUNT];

  for(int i = 0; i < LETTERS_COUNT; ++i)
  {
    std::cin >> heights[i];
  }

  std::string text;
  std::cin >> text;

  int max_height = -1;
  for(int i = 0; i < text.length(); ++i)
  {
    if(heights[text[i] - 'a'] > max_height)
    {
      max_height = heights[text[i] - 'a'];
    }
  }

  std::cout << (text.length() * max_height) << std::endl;

  return 0;
}
