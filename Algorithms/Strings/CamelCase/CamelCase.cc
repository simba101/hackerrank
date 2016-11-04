/*
Solution to the "CamelCase" challenge by HackerRank:
https://www.hackerrank.com/challenges/camelcase
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  std::string s;
  std::cin >> s;

  int ans = 1;
  for(auto it = s.begin(); it != s.end(); ++it)
  {
    if(((*it) >= 'A') && ((*it) <= 'Z'))
    {
      ans += 1;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
