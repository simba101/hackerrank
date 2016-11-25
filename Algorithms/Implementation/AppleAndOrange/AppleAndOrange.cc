/*
Solution to the "AppleAndOrange" challenge by HackerRank:
https://www.hackerrank.com/challenges/apple-and-orange
Written on 24-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>


int main(int argc, char **argv)
{
  int appleTreePosition, orangeTreePosition, roofStart, roofEnd,
          totalApples, totalOranges, fruitFallPosition, fruitFallOffset;
  std::cin >> roofStart >> roofEnd >> appleTreePosition >> orangeTreePosition
          >> totalApples >> totalOranges;

  int applesOnTheRoof = 0, orangesOnTheRoof = 0;

  for(int apple = 0; apple < totalApples; ++apple)
  {
    std::cin >> fruitFallOffset;
    fruitFallPosition = appleTreePosition + fruitFallOffset;
    if((fruitFallPosition >= roofStart) && (fruitFallPosition <= roofEnd))
    {
      applesOnTheRoof += 1;
    }
  }

  for(int orange = 0; orange < totalOranges; ++orange)
  {
    std::cin >> fruitFallOffset;
    fruitFallPosition = orangeTreePosition + fruitFallOffset;
    if((fruitFallPosition >= roofStart) && (fruitFallPosition <= roofEnd))
    {
      orangesOnTheRoof += 1;
    }
  }

  std::cout << applesOnTheRoof << std::endl << orangesOnTheRoof << std::endl;

  return 0;
}
