/*
Solution to the "Library Fine" challenge by HackerRank:
https://www.hackerrank.com/challenges/library-fine
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T = 1;

  for(int t = 0; t < T; ++t)
  {
    int dRet, mRet, yRet;
    int dDue, mDue, yDue;
    int mLate = 0, dLate = 0;
    const int dFine = 15, mFine = 500, yFine = 10000;
    int fine = 0;

    std::cin >> dRet >> mRet >> yRet;
    std::cin >> dDue >> mDue >> yDue;

    if((yRet < yDue) ||
       (yRet == yDue && mRet < mDue) ||
       (yRet == yDue && mRet == mDue && dRet <= dDue))
    {
      // fine is still 0.
    }
    else {
      // apply fine:
      if(yRet == yDue && mRet == mDue)
      {
        fine += (dRet - dDue) * dFine;
      }
      else if(yRet == yDue)
      {
        fine += (mRet - mDue) * mFine;
      }
      else {
        fine += yFine;
      }
    }

    std::cout << fine << std::endl;
  }

  return 0;
}
