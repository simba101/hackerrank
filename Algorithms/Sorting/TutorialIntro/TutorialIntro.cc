/*
Solution to the "TutorialIntro" challenge by HackerRank:
https://www.hackerrank.com/challenges/tutorial-intro
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

const int N = 1000;

int main(int argc, char **argv)
{
  int v, n;
  int t[N];
  std::cin >> v >> n;

  for(int i = 0; i < n; ++i)
  {
    std::cin >> t[i];
  }

  // performs a binary search for the number v in a sorted array:
  int low = 0, high = n - 1, curr;

  if(v == t[low])
  {
    curr = low;
  }
  else if(v == t[high])
  {
    curr = high;
  }
  else {
    curr = (high - low) / 2;
  }

  while((t[curr] != v))
  {
    if(v < t[curr])
    {
      high = curr;
    }
    else
    {
      low = curr;
    }

    curr = low + ((high - low) / 2);
  }

  std::cout << curr << std::endl;

  return 0;
}
