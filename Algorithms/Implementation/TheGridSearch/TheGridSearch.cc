/*
Solution to "The Grid Search" challenge by HackerRank:
https://www.hackerrank.com/challenges/the-grid-search
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

const int RC_MAX = 1000;

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;
  for(int t = 0; t < T; ++t)
  {
    int GR, GC;
    int PR, PC;
    char G[RC_MAX][RC_MAX];
    char P[RC_MAX][RC_MAX];
    char buf[RC_MAX];

    std::cin >> GR >> GC;
    for(int gr = 0; gr < GR; ++gr)
    {
      std::cin >> buf;
      for(int gc = 0; gc < GC; ++gc)
      {
        G[gr][gc] = buf[gc];
      }
    }

    std::cin >> PR >> PC;
    for(int pr = 0; pr < PR; ++pr)
    {
      std::cin >> buf;
      for(int pc = 0; pc < PC; ++pc)
      {
        P[pr][pc] = buf[pc];
      }
    }

/*
    std::cout << "Grid:" << std::endl;
    for(int i = 0; i < GR; ++i)
    {
      for(int j = 0; j < GC; ++j)
        std::cout << G[i][j];
      std::cout << std::endl;
    }

    std::cout << "\nPattern:" << std::endl;
    for(int i = 0; i < PR; ++i)
    {
      for(int j = 0; j < PC; ++j)
        std::cout << P[i][j];
      std::cout << std::endl;
    }
    std::cout << std::endl;
*/

    bool isPatternFound = false;
    for(int gr = 0; ((gr < GR) && (!isPatternFound)); ++gr)
    {
      for(int gc = 0; ((gc < GC) && (!isPatternFound)); ++gc)
      {
        if(G[gr][gc] == P[0][0])
        {
          // check whether the pattern may fit here:
          if((gr + PR <= GR) && (gc + PC <= GC))
          {
            //std::cout << "Initial match: " << gr << ", " << gc << std::endl;
            bool isStillValidPattern = true;
            for(int pr = 0; ((pr < PR) && (isStillValidPattern)); ++pr)
            {
              for(int pc = 0; ((pc < PC) && (isStillValidPattern)); ++pc)
              {
                //std::cout << "Checking: G[" << gr + pr << "][" << gc + pc
                //                            << "] != P[" << pr << "][" << pc << "]\n";
                if(G[gr + pr][gc + pc] != P[pr][pc])
                  isStillValidPattern = false;
              }
            }
            if(isStillValidPattern)
            {
              isPatternFound = true;
            }
          }

        }
      }
    }

    if(isPatternFound)
    {
      std::cout << "YES" << std::endl;
    }
    else
    {
      std::cout << "NO" << std::endl;
    }

  }

  return 0;
}
