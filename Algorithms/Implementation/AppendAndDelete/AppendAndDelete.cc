/*
Solution to the "AppendAndDelete" challenge by HackerRank:
https://www.hackerrank.com/challenges/append-and-delete
Written on 08-02-2017 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <string>


int get_matching_length(std::string &first, std::string &second)
{
  int len = 0;
  while(first[len] == second[len])
  {
    len += 1;
  }

  return len;
}

int main(int argc, char **argv)
{
  std::string A, B;
  std::cin >> A >> B;
  int changes;
  std::cin >> changes;

  // Special case: if the number of allowed changes
  //  >= (length of A + length of B), then the answer is YES:
  if(changes >= (A.size() + B.size()))
  {
    std::cout << "Yes" << std::endl;
  }

  else
  {
    // Gets the size of the common prefix in both A and B.
    // This prefix does not need to be mutated:
    int matching_length = get_matching_length(A, B);

    // Calculates how many characters from A have to be deleted,
    // so that the A-string becomes a common prefix:
    int to_delete_from_A = A.size() - matching_length;

    // Calculates how many characters have to be added to the common prefix
    // so that the B-string is obtained as a result:
    int to_append = B.size() - matching_length;

    // How many changes is that in total?:
    int total = to_delete_from_A + to_append;

    // Mutation is possible if the number of necessary changes is equal to the
    // number of allowed changes, or the number of allowed changes is greater
    // than the number of allowed changes by any multiple of two (this is
    // equal to adding and immediately deleting a "z" at the end).
    // In effect the answer is YES if (changes - total) mod 2 == 0.

    bool is_doable = ((changes - total >= 0) && ((changes - total) % 2 == 0));
    std::cout << (is_doable ? "Yes" : "No") << std::endl;
  }


  return 0;
}
