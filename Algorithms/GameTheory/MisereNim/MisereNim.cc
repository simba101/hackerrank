/*
Solution to the "MisereNim" challenge by HackerRank:
https://www.hackerrank.com/challenges/misere-nim-1
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int max_heap = 0;
    int xored = 0;
    int current_heap;

    int heaps_count;
    std::cin >> heaps_count;
    for(int h = 0; h < heaps_count; ++h)
    {
      std::cin >> current_heap;
      if(current_heap > max_heap)
        max_heap = current_heap;

      xored ^= current_heap;
    }

    if(max_heap <= 1)
    {
      std::cout << (xored == 1 ? "Second" : "First") << std::endl;
    }
    else
    {
      std::cout << (xored == 0 ? "Second" : "First") << std::endl;
    }
  }

  return 0;
}
