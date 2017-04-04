/*
Solution to the "CatsAndAMouse" challenge by HackerRank:
https://www.hackerrank.com/challenges/cats-and-a-mouse
Written on 17-03-2017 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>


int abs(int num)
{
  return (num < 0 ? -num : num);
}

int main(int argc, char **argv)
{
  // First line of input is a number of queries, 1 <= T <= 100
  int T;
  std::cin >> T;

  for (int t = 0; t < T; ++t)
  {
    // Each of T next lines of input are in a form of three integers:
    int catA;
    int catB;
    int mouseC;
    std::cin >> catA >> catB >> mouseC;
    // 1 <= catA, catB, mouseC <= 100

    int distAC = abs(catA - mouseC);
    int distBC = abs(catB - mouseC);

    if (distAC > distBC)
    {
      // Cat B will catch the mouse C first.
      std::cout << "Cat B" << std::endl;
    }
    else if (distAC < distBC)
    {
      // Cat A will catch the mouse C first.
      std::cout << "Cat A" << std::endl;
    }
    else
    {
      // The cats will fight and the mouse will escape.
      std::cout << "Mouse C" << std::endl;
    }
  }

  return 0;
}
