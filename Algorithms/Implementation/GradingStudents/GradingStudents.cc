/*
Solution to the "GradingStudents" challenge by HackerRank:
https://www.hackerrank.com/challenges/grading
Written on 09-03-2017 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>


int main(int argc, char **argv)
{
  int N, grade, base, mul5, ans;
  std::cin >> N;
  for (int n = 0; n < N; ++n)
  {
    std::cin >> grade;
    ans = grade;
    if (grade >= 38)
    {
      base = grade / 5;
      mul5 = ((base + 1) * 5);
      ans = ((mul5 - grade < 3) ? mul5 : grade);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}
