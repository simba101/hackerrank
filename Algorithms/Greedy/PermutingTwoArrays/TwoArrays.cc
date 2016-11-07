/*
Solution to the "PermutingTwoArrays" challenge by HackerRank:
https://www.hackerrank.com/challenges/two-arrays
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N, K, number;
    std::vector<int> A, B;

    std::cin >> N >> K;
    for(int n = 0; n < N; ++n)
    {
      std::cin >> number;
      A.push_back(number);
    }
    for(int n = 0; n < N; ++n)
    {
      std::cin >> number;
      B.push_back(number);
    }
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end(), std::greater<int>());

    bool canPick = true;
    int n = 0;
    while(canPick && (n < N))
    {
      if(A[n] + B[n] < K)
      {
        canPick = false;
      }
      n += 1;
    }

    std::cout << (canPick ? "YES" : "NO") << std::endl;
  }

  return 0;
}
