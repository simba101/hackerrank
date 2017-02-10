/*
Solution to the "BombermanGame" challenge by HackerRank:
https://www.hackerrank.com/challenges/bomber-man
Written on 10-02-2017 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector< std::vector< int > > Board;

// ----------------------------------------------------------------------------
// Constant values:
// ----------------------------------------------------------------------------
const char BOMB_CHAR = 'O';
const char EMPTY_CHAR = '.';
const char BORDER_CHAR = '*';
const int BOMB_TIMEOUT = 3;

// ----------------------------------------------------------------------------
// Globally accessible variables:
// ----------------------------------------------------------------------------
int height, width, target_time;
Board current_board;
std::vector< Board > history;

// ----------------------------------------------------------------------------
// Helper methods:
// ----------------------------------------------------------------------------
void prepare_board()
{
  // Resizes the board for (H+2) x (W+2) cells [requested size + the border]:
  current_board.resize(height + 2);
  for(int h = 0; h < height + 2; ++h)
  {
    current_board[h].resize(width + 2, 0); // fills the cells with value of 0.
  }

  // Generates the border:
  for(int h = 0; h < height + 2; ++h)
  {
    current_board[h][0] = -1;            // the left-side border
    current_board[h][width + 1] = -1;    // the right-side border
  }
  for(int w = 1; w <= width; ++w)
  {
    current_board[0][w] = -1;            // the top-side border
    current_board[height + 1][w] = -1;   // the bottom-side border
  }
}

void scan_initial_board()
{
  char incoming;
  for(int h = 1; h <= height; ++h)
  {
    for(int w = 1; w <= width; ++w)
    {
      std::cin >> incoming;
      if(BOMB_CHAR == incoming)
      {
        current_board[h][w] = BOMB_TIMEOUT;
      }
    }
  }
}

void copy_board_to_history(int t)
{
  history[t] = current_board;
}

void print_full_board(Board &b)
{
  for(int h = 0; h < height + 2; ++h)
  {
    for(int w = 0; w < width + 2; ++w)
    {
      if(b[h][w] == -1)
      {
        std::cout << '*';
      }
      else
      {
        std::cout << b[h][w];
      }
    }
    std::cout << std::endl;
  }
}

// MODIFIES THE CURRENT_BOARD, PLEASE PASS BOARDS FROM HISTORY:
void time_step(Board &b)
{
  // Copies the entire contents of the board to the current_board,
  // decreasing timers on the bombs by 1:
  for(int h = 1; h <= height; ++h)
  {
    for(int w = 1; w <= width; ++w)
    {
      current_board[h][w] = std::max(b[h][w] - 1, 0);
    }
  }

  // Explodes the bombs where counter reached zero:
  for(int h = 1; h <= height; ++h)
  {
    for(int w = 1; w <= width; ++w)
    {
      if(1 == b[h][w])
      {
        if(b[h-1][w] != BORDER_CHAR)
          current_board[h-1][w] = 0;
        if(b[h+1][w] != BORDER_CHAR)
          current_board[h+1][w] = 0;
        if(b[h][w-1] != BORDER_CHAR)
          current_board[h][w-1] = 0;
        if(b[h][w+1] != BORDER_CHAR)
          current_board[h][w+1] = 0;
      }
    }
  }
}

void fill_with_fresh_bombs()
{
  for(int h = 1; h <= height; ++h)
  {
    for(int w = 1; w <= width; ++w)
    {
      if(0 == current_board[h][w])
      {
        current_board[h][w] = BOMB_TIMEOUT;
      }
    }
  }
}

void print_board(Board &b)
{
  for(int h = 1; h <= height; ++h)
  {
    for(int w = 1; w <= width; ++w)
    {
      std::cout << (0 == b[h][w] ? EMPTY_CHAR : BOMB_CHAR);
    }
    std::cout << std::endl;
  }
}

int main(int argc, char **argv)
{
  std::cin >> height >> width >> target_time;
  int current_time = 0;

  // it is enough to know the state of the board
  // in time steps t={0, 1, 2, 3, 4, 5, 6}
  // to be able to predict its exact state at any time.
  // The pattern is: {0, 1, 2, 3, 4, 5, 6, 3, 4, 5, 6, 3, ...}
  history.resize(7);

  // Time = 0, some initial layout of bombs is scanned:
  prepare_board();
  scan_initial_board();
  copy_board_to_history(0);

  // Time = 1, bomberman does nothing:
  time_step(history[0]);
  copy_board_to_history(1);

  // Time = 2, bomberman fills empty cells with fresh bombs:
  time_step(history[1]);
  fill_with_fresh_bombs();
  copy_board_to_history(2);

  // Time = 3, bomberman does nothing:
  time_step(history[2]);
  copy_board_to_history(3);

  // Time = 4, bomberman fills empty cells with fresh bombs:
  time_step(history[3]);
  fill_with_fresh_bombs();
  copy_board_to_history(4);

  // Time = 5, bomberman does nothing:
  time_step(history[4]);
  copy_board_to_history(5);

  // Time = 6, bomberman fills empty cells with fresh bombs:
  time_step(history[5]);
  fill_with_fresh_bombs();
  copy_board_to_history(6);

  // Prints the exact layout of board at time target_time:
  if(target_time <= 2)
  {
    print_board(history[target_time]);
  }
  else
  {
    print_board(history[(target_time + 1) % 4 + 3]);
  }

  return 0;
}
