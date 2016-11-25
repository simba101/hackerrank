/*
Solution to the "HappyLadybugs" challenge by HackerRank:
https://www.hackerrank.com/challenges/happy-ladybugs
Written on 24-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <vector>
#include <algorithm>

const int CHAR_SIZE = 256; // sizeof(char)

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for (int t = 0; t < T; ++t)
  {
    int N;
    std::cin >> N;

    std::vector<char> board;
    board.resize(N + 2);

    // Adds the border-case guards:
    board[0] = board[N + 1] = '*';

    bool are_there_empty_spaces = false;

    // Reads the board
    for(int n = 1; n <= N; ++n)
    {
      std::cin >> board[n];
      if('_' == board[n])
      {
        are_there_empty_spaces = true;
      }
    }

    // if there is a possibility to sort the string, it should be done:
    if(are_there_empty_spaces)
    {
      std::sort(board.begin(), board.end());
    }

    // checks whether all the bugs are happy:
    bool are_happy = true;
    for(int i = 1; i <= N; ++i)
    {
      if((board[i - 1] != board[i]) && (board[i + 1] != board[i]))
      {
        // This ladybug is surrounded by different-colored bugs,
        // and in effect is not happy.
        are_happy = false;
      }
    }

    // Prints the answer, which is whether all the bugs are happy.
    std::cout << (are_happy ? "YES" : "NO") << std::endl;
  }

  return 0;
}
