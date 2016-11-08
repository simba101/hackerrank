/*
Solution to the "MandragoraForest" challenge by HackerRank:
https://www.hackerrank.com/challenges/mandragora
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

// Constraints:
const int MAX_TESTCASES       =       100000;   // 10^5
const int MAX_MANDRAGORAS     =       100000;   // 10^5
const int MAX_HEALTH          =       10000000; // 10^7

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    uint64_t S;
    uint64_t P;

    int N;
    std::vector<uint64_t> H;

    std::cin >> N;
    H.resize(N);
    for(int n = 0; n < N; ++n)
    {
      std::cin >> H[n];
    }

    // sorts the array:
    std::sort(H.begin(), H.end());

    uint64_t max_exp = 0;
    uint64_t curr_exp;
    bool is_optimum_reached = false;


    // SUBOPTIMAL SOLUTION - TOO SLOW TO PASS A TIME-LIMIT:
/*
    for(int mandragoras_eaten = N - 1;
        (!is_optimum_reached && mandragoras_eaten >= 0);
        --mandragoras_eaten)
    {
      S = 1 + mandragoras_eaten;
      P = 0;
      for(int m = mandragoras_eaten; m < N; ++m)
      {
        P += (S * H[m]);
      }

      if(P > max_exp)
      {
        max_exp = P;
      }
      else
      {
        is_optimum_reached = true;
      }
    } // for mandragoras_eaten
*/

////////////////////////////////////////////////////////////////////////////////
//  A better (and lightning fast) solution utilizing the following equation:  //
//                                                                            //
//          E_k = E_(k-1) - H[k - 1] * k + sum(H[k + 1] .. H[N - 1])          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

    // Calculates the sum of all the battled mandragoras' health:
    uint64_t sum = 0;
    for(int m = 0; m < N; ++m)
    {
      sum += H[m];
    }

    // The total experience for battling all the mandragoras equals
    // the sum calculated just before (number of eaten m-goras: zero):
    max_exp = sum;
    sum -= H[0];

    for(int k = 1; !is_optimum_reached; ++k)
    {
      curr_exp = max_exp - (H[k - 1] * k) + sum;
      sum -= H[k];
      if(max_exp < curr_exp)
      {
        max_exp = curr_exp;
      }
      else
      {
        is_optimum_reached = true;
      }
    } // for-loop covering increasing number of eaten mandragoras

    std::cout << max_exp << std::endl;
  } // for-loop covering t'th testcase

  return 0;
}
