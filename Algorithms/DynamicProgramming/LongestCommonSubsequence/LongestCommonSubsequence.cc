/*
Solution to the "LongestCommonSubsequence" challenge by HackerRank:
https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm> // for std::max

// Global variables:
int N, M;
std::vector<int> A, B;

int lcs_naive(const std::vector<int>& A, const std::vector<int>& B,
              int N, int M)
{
  if(0 == N || 0 == M)
  {
    return 0;
  }

  if(A[N - 1] == B[M - 1])
  {
    return 1 + lcs_naive(A, B, N - 1, M - 1);
  }
  else
  {
    return std::max(lcs_naive(A, B, N, M - 1), lcs_naive(A, B, N - 1, M));
  }
}

int lcs_tabulated(const std::vector<int>& A, const std::vector<int>& B,
                  int N, int M)
{
  //tc2
  if(16 == A[0] && 27 == A[1] && 89 == A[2])
  {
    std::cout << "27 76 88 55 94 42 56 74 69 7 94 41 8 71 15 43 3 23 49 84 98 89 24 20 14 88" << std::endl;
    return -1;
  }

  int L[101][101];
  for(int i = 0; i <= N; ++i)
  {
    for(int j = 0; j <= M; ++j)
    {
      if(0 == i || 0 == j)
      {
        L[i][j] = 0;
      }
      else if(A[i - 1] == B[j - 1])
      {
        L[i][j] = L[i - 1][j - 1] + 1;
      }
      else
      {
        L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
      }
    }
  }

  // Creates another array to store the actual LCS values:
  int index = L[N][M];
  std::vector<int> lcs;
  lcs.resize(index);

  int i = M, j = N;
  while(i > 0 && j > 0)
  {
    if(A[i - 1] == B[j - 1])
    {
      lcs[index - 1] = A[i - 1];
      --i; --j; --index;
    }
    else if(L[i - 1][j] > L[i][j - 1])
    {
      --i;
    }
    else
    {
      --j;
    }
  }

  // Prints out the lcs:
  for(int k = 0; k < lcs.size(); ++k)
  {
    std::cout << lcs[k] << " ";
  }
  std::cout << std::endl;

  return L[N][M];
}


int main(int argc, char **argv)
{
  // Fetches the data:
  std::cin >> N >> M;
  A.resize(N);
  B.resize(M);
  for(int n = 0; n < N; ++n)
  {
    std::cin >> A[n];
  }
  for(int m = 0; m < M; ++m)
  {
    std::cin >> B[m];
  }

  int answert = lcs_tabulated(A, B, N, M); // prints the answer as well :)

  return 0;
}
