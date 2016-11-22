/*
Solution to the "Euler018" challenge by HackerRank:
https://www.hackerrank.com/contests/projecteuler/challenges/euler018
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>

void print_triangle(const std::vector<std::vector<int>>& t)
{
  for(int n = 0; n < t.size(); ++n)
  {
    for(int k = 0; k < t[n].size(); ++k)
    {
      std::cout << t[n][k] << " ";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    std::vector<std::vector<int>> triangle;
    std::vector<std::vector<int>> answers;
    int N;
    std::cin >> N;
    triangle.resize(N);
    answers.resize(N);
    for(int n = 0; n < N; ++n)
    {
      triangle[n].resize(n + 1);
      answers[n].resize(n + 1);
      for(int k = 0; k <= n; ++k)
      {
        std::cin >> triangle[n][k];
      }
    }

    // Rewrites the bottom row of the triangle to the answers supervector:
    for(int n = 0; n < N; ++n)
    {
      answers[N - 1][n] = triangle[N - 1][n];
    }

    // Goes bottom-up searching for the best path:
    for(int n = N - 2; n >= 0; --n)
    {
      for(int k = 0; k <= n; ++k)
      {
        answers[n][k] = triangle[n][k] +
            std::max(answers[n + 1][k], answers[n + 1][k + 1]);
      }
    }

    std::cout << answers[0][0] << std::endl;
  }

  return 0;
}
