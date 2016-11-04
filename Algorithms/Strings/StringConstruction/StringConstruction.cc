/*
Solution to the "StringConstruction" challenge by HackerRank:
https://www.hackerrank.com/challenges/string-construction
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>
#include <map>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    std::string s;
    std::cin >> s;
    std::map<char, bool> m;
    for(int c = 0; c < s.size(); ++c)
    {
      m[s[c]] = true;
    }

    int ans = 0;
    for(char c = 'a'; c <= 'z'; ++c)
    {
      if(m.find(c) != m.end())
      {
        ans += 1;
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}
