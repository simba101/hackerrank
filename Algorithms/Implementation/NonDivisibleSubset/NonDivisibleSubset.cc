/*
Solution to the "NonDivisibleSubset" challenge by HackerRank:
https://www.hackerrank.com/challenges/non-divisible-subset
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>

// boundaries:
constexpr int MAXN = 100000; // 10^5
constexpr int MAXK = 100;
constexpr int MAXAi = 1000000000; // 10^9

int main(int argc, char **argv)
{
  int N, K;
  std::cin >> N >> K;

  // Prepares a vector of remainders which will hold the count of input numbers
  // that give such remainder when divided by K. Sets it initially to zeroes:
  std::vector<int> remainders;
  remainders.resize(K);
  for(int k = 0; k < K; ++k)
  {
    remainders[k] = 0;
  }

  // Reads the input numbers one-by-one, recording their remainders when divided
  // by K:
  int number, remainder;
  for(int n = 0; n < N; ++n)
  {
    std::cin >> number;
    remainder = number % K;
    remainders[remainder] += 1;
  }


  // since (a + b) % K == (a % K) + (b % K), the larger of pair-wise remainders
  // should be included in the answer:
  int answer = 0;
  int x = 1, y = K - 1;
  while(x < y)
  {
    answer += (remainders[x] > remainders[y] ? remainders[x] : remainders[y]);
    ++x;
    --y;
  }

  // a special case: if K % 2 == 0, at most 1 value with remainder K / 2
  // may be added to the set:
  if(x == y) // true only for even K's
  {
    if(remainders[x] > 0)
    {
      answer += 1;
    }
  }

  // a special case: if K is 0, then at most 1 value which is divided by K
  // evenly may be added to the set:
  if(remainders[0] > 0)
  {
    answer += 1;
  }

  std::cout << answer << std::endl;

  return 0;
}
