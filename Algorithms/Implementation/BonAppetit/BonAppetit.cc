/*
Solution to the "BonAppetit" challenge by HackerRank:
https://www.hackerrank.com/challenges/bon-appetit
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int count, omitted, item;
  std::cin >> count >> omitted;
  int total = 0;
  for(int i = 0; i < count; ++i)
  {
    std::cin >> item;
    if(!(i == omitted))
    {
      total += item;
    }
  }

  int actual = total / 2;
  int charged;
  std::cin >> charged;

  int diff = charged - actual;

  if(0 == diff)
  {
    std::cout << "Bon Appetit" << std::endl;
  }
  else
  {
    std::cout << diff << std::endl;
  }

  return 0;
}
