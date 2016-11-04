/*
Solution to the "SuperReducedString" challenge by HackerRank:
https://www.hackerrank.com/challenges/reduced-string
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

constexpr int MAXLEN = 100 + 2;

int main(int argc, char **argv)
{
  char input[MAXLEN];
  std::cin >> input;

  bool modified = true;
  while(modified)
  {
    bool found = false;
    int k = 0;
    while((!found) && (input[k + 1] != '\0'))
    {
      found = (input[k] == input[k + 1]);
      ++k;
    }
    --k;

    if(found)
    {
      // transplanting the 2nd char...
      int f = k + 1;
      do
      {
        input[f] = input[f + 1];
        ++f;
      }
      while(input[f] != '\0');

      // transplanting the 1st char...
      f = k;
      do
      {
        input[f] = input[f + 1];
        ++f;
      }
      while(input[f] != '\0');
      // ... done!
      // std::cout << "squashed position: " << k << ", now is: " << input << std::endl;
    }

    modified = found;
  }

  if('\0' == input[0])
  {
    std::cout << "Empty String" << std::endl;
  }
  else
  {
    std::cout << input << std::endl;
  }


  return 0;
}
