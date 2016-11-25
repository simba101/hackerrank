/*
Solution to the "StrangeAdvertising" challenge by HackerRank:
https://www.hackerrank.com/challenges/strange-advertising
Written on 24-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>


const int MAX_DAYS = 50 + 1;
const int INITIAL_PEOPLE = 5;

int likes[MAX_DAYS];
int answers[MAX_DAYS];

void precompute_answers()
{
  likes[1] = INITIAL_PEOPLE / 2;
  for(int day = 2; day < MAX_DAYS; ++day)
  {
    likes[day] = (3 * likes[day - 1]) / 2;
  }

  int accumulator = 0;
  for(int day = 1; day < MAX_DAYS; ++day)
  {
    accumulator += likes[day];
    answers[day] = accumulator;
  }
}


int main(int argc, char **argv)
{
  precompute_answers();

  int n;
  std::cin >> n;
  std::cout << answers[n] << std::endl;

  return 0;
}
