/*
Solution to the "BeautifulBinaryString" challenge by HackerRank:
https://www.hackerrank.com/challenges/beautiful-binary-string
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  int l;
  std::cin >> l;

  std::string s;
  std::cin >> s;

  int changes = 0;

  for(int k = 0; k < l - 2; ++k)
  {
    if(('0' == s[k]) && ('1' == s[k + 1]) && ('0' == s[k + 2]))
    {
      // what a bloody ugly number! Let's fix it:
      s[k + 2] = '1';
      changes += 1;
    }
  }

  std::cout << changes << std::endl;

  return 0;
}
