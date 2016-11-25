/*
Solution to the "BeautifulDaysMovies" challenge by HackerRank:
https://www.hackerrank.com/challenges/beautiful-days-at-the-movies
Written on 24-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <cmath>


int reverse(int number)
{
  int ans = 0;
  while(number > 0)
  {
    ans = ans * 10 + (number % 10);
    number /= 10;
  }

  return ans;
}

bool is_beautiful(int day, int divisor)
{
  return (std::abs(day - reverse(day)) % divisor == 0);
}

int main(int argc, char **argv)
{
  int minDay, maxDay, divisor;
  int ans = 0;

  std::cin >> minDay >> maxDay >> divisor;

  for(int k = minDay; k <= maxDay; ++k)
  {
    if(is_beautiful(k, divisor))
    {
      ans += 1;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
