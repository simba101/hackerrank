/*
Solution to the "GridChallenge" challenge by HackerRank:
https://www.hackerrank.com/challenges/grid-challenge
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N;
    std::cin >> N;

    std::vector<std::string> a;
    a.reserve(N);

    for(int n = 0; n < N; ++n)
    {
      std::string row;
      std::cin >> row;
      std::sort(row.begin(), row.end());
      a.push_back(row);
    }

    // so now each row is in sorted (lexical) order.
    // outputs "YES" if columns are also sorted, "NO" otherwise.
    bool isSorted = true;
    for(int col = 0; ((col < N) && (isSorted)); ++col)
    {
      for(int row = 1; ((row < N) && (isSorted)); ++row)
      {
        if(a[row][col] < a[row - 1][col])
        {
          isSorted = false;
        }
      }
    }

    std::cout << (isSorted ? "YES" : "NO") << std::endl;
  }

  return 0;
}
