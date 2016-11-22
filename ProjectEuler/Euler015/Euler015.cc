/*
Solution to the "Euler015" challenge by HackerRank:
https://www.hackerrank.com/contests/projecteuler/challenges/euler015
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

constexpr int MAX_N = 500;
constexpr int MAX_M = 500;
constexpr long bigprime = 1e9 + 7;

static long answers[MAX_N + 1][MAX_M + 1];

void calculate_answers()
{
  // corner cases: exactly 1 way to get to the bottom right from any position
  // on the bottom row or on the right column:
  for(int n = 0; n < MAX_N; ++n)
  {
    answers[n][0] = 1;
    answers[0][n] = 1;
  }

  for(int n = 1; n <= MAX_N; ++n)
  {
    for(int m = 1; m <= MAX_M; ++m)
    {
      answers[n][m] = (answers[n - 1][m] + answers[n][m - 1]) % bigprime;
    }
  }
}

int main(int argc, char **argv)
{
  calculate_answers();
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N, M;
    std::cin >> N >> M;

    std::cout << answers[N][M] << std::endl;
  }

  return 0;
}
