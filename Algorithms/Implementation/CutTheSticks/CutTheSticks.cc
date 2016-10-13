/*
Solution to "Cut the Sticks" challenge by HackerRank:
https://www.hackerrank.com/challenges/cut-the-sticks
by simba (szczerbiakadam@gmail.com)
*/

#include <iostream>

const int NLIMIT = 1000;

int main(int argc, char **argv)
{
  int N;
  int sticks[NLIMIT];
  int minLength, noOfSticksTotal;

  std::cin >> N;

  noOfSticksTotal = 0;
  for(int n = 0; n < N; ++n)
  {
    std::cin >> sticks[n];
    if(sticks[n] > 0)
      ++noOfSticksTotal;
  }

  do {
    minLength = 10101;
    for(int n = 0; n < N; ++n)
    {
      if((sticks[n] > 0) && (sticks[n] < minLength))
        minLength = sticks[n];
    }

    std::cout << noOfSticksTotal << std::endl;

    // performs the cut operation:
    for(int n = 0; n < N; ++n)
    {
      if(sticks[n] > 0)
        sticks[n] -= minLength;
      if(sticks[n] < 0)
        sticks[n] = 0;
    }

    // counts the total sticks count:
    noOfSticksTotal = 0;
    for(int n = 0; n < N; ++n)
    {
      if(sticks[n] > 0)
        ++noOfSticksTotal;
    }
  } while(noOfSticksTotal > 0);


  return 0;
}
