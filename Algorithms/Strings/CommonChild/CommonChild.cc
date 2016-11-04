/*
Solution to the "CommonChild" challenge by HackerRank:
https://www.hackerrank.com/challenges/common-child
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

const int MAX_LENGTH = 5000 + 2;
int arr[MAX_LENGTH][MAX_LENGTH];
std::string a, b;

int LCSLength(std::string a, std::string b)
{
  for(int i = 0; i <= a.length(); ++i)
  {
    arr[i][0] = 0;
  }
  for(int j = 0; j <= b.length(); ++j)
  {
    arr[0][j] = 0;
  }

  for(int i = 1; i <= a.length(); ++i)
  {
    for(int j = 1; j <= b.length(); ++j)
    {
      if(a[i-1] == b[j-1])
      {
        arr[i][j] = arr[i-1][j-1] + 1;
      }
      else
      {
        // arr[i][j] = max( arr[i][j-1], arr[i-1][j] ):
        arr[i][j] = (arr[i][j-1] > arr[i-1][j]) ? arr[i][j-1] : arr[i-1][j];
      }
    }
  }

  return arr[a.length()][b.length()];
}

void print_array()
{
  // Prints out the header:
  std::cout << "\t-\t";
  for(int j = 1; j <= b.length(); ++j)
  {
    std::cout << b[j-1] << "\t";
  }
  std::cout << std::endl << "-\t";
  for(int j = 0; j <= b.length(); ++j)
  {
    std::cout << arr[0][j] << "\t";
  }
  std::cout << std::endl;

  // Prints out other rows:
  for(int i = 1; i <= a.length(); ++i)
  {
    std::cout << a[i-1] << "\t";
    std::cout << arr[i][0] << "\t";
    for(int j = 1; j <= b.length(); ++j)
    {
      std::cout << arr[i][j] << "\t";
    }
    std::cout << std::endl;
  }
}

void print_array_simple()
{
  for(int i = 1; i <= a.length(); ++i)
  {
    for(int j = 1; j <= a.length(); ++j)
    {
      std::cout << arr[i][j] << "\t";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char **argv)
{
  std::cin >> a >> b;

  int answer = LCSLength(a, b);
  std::cout << answer << std::endl;

  return 0;
}
