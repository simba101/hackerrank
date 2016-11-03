/*
Solution to the "TheTimeInWords" challenge by HackerRank:
https://www.hackerrank.com/challenges/the-time-in-words
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

std::string numbers[] = { "one", "two", "three", "four", "five", "six",
                       "seven", "eight", "nine", "ten", "eleven", "twelve",
                       "thirteen", "fourteen", "fifteen", "sixteen",
                       "seventeen", "eighteen", "nineteen", "twenty",
                       "twenty one", "twenty two", "twenty three",
                       "twenty four", "twenty five", "twenty six",
                       "twenty seven", "twenty eight", "twenty nine",
                       "thirty" };


int main(int argc, char **argv)
{
  int T = 1;

  for(int t = 0; t < T; ++t)
  {
    int H, M;
    std::cin >> H >> M;

    // special case - full hour:
    if(M == 0)
    {
      std::cout << numbers[H - 1] << " o' clock" << std::endl;
    }
    else
    {
      // applies the right suffix - either past or to <HOUR>:
      std::string suffix;
      if(M <= 30)
      {
        suffix = " past " + numbers[H - 1];
      }
      else
      {
        suffix = " to " + numbers[H % 12];

        // calculates how many minutes are left to full hour:
        M = 60 - M;
      }

      std::string minutes;
      // special case - minutes form full quarters:
      if(M % 15 == 0)
      {
        minutes = (M == 30) ? "half" : "quarter";
      }
      else
      {
        minutes = numbers[M - 1];
        minutes += (M == 1) ? " minute" : " minutes";
      }

      std::cout << minutes << suffix << std::endl;
    }
  }

  return 0;
}
