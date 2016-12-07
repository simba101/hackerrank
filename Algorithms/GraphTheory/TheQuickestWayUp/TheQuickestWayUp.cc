/*
Solution to the "TheQuickestWayUp" challenge by HackerRank:
https://www.hackerrank.com/challenges/the-quickest-way-up
Written on 07-12-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>

const int BOARD_SIZE = 100; // The count of cells in a Snakes & Ladders board.
const int DICE_SIDES = 6;
const int INFINITY = 101101; // Any number greater than 100 will do, actually.

// Represents a cell in a Snakes & Ladders board.
class Cell
{
 public:
  Cell(int number = -1, int reachability = INFINITY) :
      _number(number), _reachability(reachability)
  {
    // Initially there are no teleporters on the board:
    _teleporter = number;
  }

 public:
  // Holds the number of the cell on a game board, in range {1, 2, ..., 100}:
  // Will probably be unused, but it's nice to have it :)
  int _number;

  // Used to indicate in how many turns this Cell may be reached:
  int _reachability;

  // Indicates the field at the end of a ladder/snake starting on this Cell.
  // If this Cell does not start with a ladder/snake, its own number is used,
  // so that the empty cell "teleports to itself":
  int _teleporter;
};


static Cell board[BOARD_SIZE + 1];


// Clears the board, so that the new set of snakes/ladders may be tested.
void clear_board()
{
  for(int i = 1; i <= BOARD_SIZE; ++i)
  {
    board[i]._number = board[i]._teleporter = i;
    board[i]._reachability = INFINITY;
  }
}

// Reads the teleporters from the standard input and applies them to the board.
void read_and_apply_teleporters()
{
  int iterations, entry, egress;

  // Goes twice - one pass is for ladders, and the other is for snakes:
  for(int round = 0; round < 2; ++round)
  {
    // Reads the number of ladders/snakes:
    std::cin >> iterations;

    // Applies the ladders/snakes:
    for(int i = 0; i < iterations; ++i)
    {
      std::cin >> entry >> egress;
      board[entry]._teleporter = egress;
    }
  }
}

// Recursively finds out the minimum number of dice rolls
// required to reach every Cell in the board:
void explore(int cell_number, int current_reachability)
{
  // Follows the teleporter in this cell:
  cell_number = board[cell_number]._teleporter;

  // If reached this cell in fewer steps than before,
  // updates the reachability and explores further:
  if(current_reachability < board[cell_number]._reachability)
  {
    board[cell_number]._reachability = current_reachability;
    for(int i = 1; i <= DICE_SIDES; ++i)
    {
      explore(cell_number + i, current_reachability + 1);
    }
  }
}

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for (int t = 0; t < T; ++t)
  {
    clear_board();
    read_and_apply_teleporters();
    explore(1, 0);

    int ans =
        (INFINITY == board[100]._reachability) ? -1 : board[100]._reachability;

    std::cout << ans << std::endl;
  }

  return 0;
}
