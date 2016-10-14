/*
Solution to the "LisaWorkbook" challenge by HackerRank:
https://www.hackerrank.com/challenges/lisa-workbook
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

const int NLIMIT = 100;

int main(int argc, char **argv)
{
  int n, k;
  int t[NLIMIT];

  // Read problem specifications from the standard input:
  std::cin >> n >> k;
  for(int i = 0; i < n; ++i)
  {
    std::cin >> t[i];
  }

  int currentPage = 1;
  int specials = 0;

  for(int i = 0; i < n; ++i)
  {

    for(int p = 1; p <= t[i]; ++p)
    {
      if(p == currentPage)
      {
        specials += 1;
      }

      if(p % k == 0)
      {
        currentPage += 1;
      }
    }

    // starts new page for a new chapter, iff current page
    // has not been already filled up.
    if(t[i] % k != 0)
    {
      currentPage += 1;
    }
  }

  std::cout << specials << std::endl;
}

