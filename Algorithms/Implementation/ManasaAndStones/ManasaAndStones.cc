/*
Solution to the "ManasaAndStones" challenge by HackerRank:
https://www.hackerrank.com/challenges/manasa-and-stones
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N;
    int A, B;
    std::cin >> N >> A >> B;
    int stoneBigger, stoneSmaller;

    if(A == B)
    {
      std::cout << (N - 1) * A << std::endl;
    }
    else {
      if(A > B)
      {
        stoneBigger = A;
        stoneSmaller = B;
      }
      else
      {
        stoneBigger = B;
        stoneSmaller = A;
      }

      for(int comb = 0; comb < N ; ++comb)
      {
        int finalValue = 0;
        for(int k = 0; k < comb; ++k)
        {
          finalValue += stoneBigger;
        }
        for(int p = comb + 1; p < N; ++p)
        {
          finalValue += stoneSmaller;
        }

        std::cout << finalValue << " ";
      }
      std::cout << std::endl;
    }
  }

  return 0;
}
