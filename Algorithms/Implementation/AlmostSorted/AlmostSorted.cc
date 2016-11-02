/*
Solution to the "AlmostSorted" challenge by HackerRank:
https://www.hackerrank.com/challenges/almost-sorted
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
  std::vector<int> input;
  int N;
  std::cin >> N;

  input.resize(N);
  for(int n = 0; n < N; ++n)
  {
    std::cin >> input[n];
  }

  int firstDisplacement = -1, lastDisplacement = -1, displacementsCount = 0;

  std::vector<int> sorted = input;
  std::sort(sorted.begin(), sorted.end());

  // Counts the displacements and remembers their indices:
  for(int n = 0; n < N; ++n)
  {
    if(input[n] != sorted[n])
    {
      if(firstDisplacement == -1)
      {
        firstDisplacement = n;
      }
      lastDisplacement = n;
      displacementsCount += 1;
    }
  }

  // 1. If the array is already sorted, output "yes" on the first line.
  if(0 == displacementsCount)
  {
    std::cout << "yes" << std::endl;
  }
  else
  {
    // 2. If you can sort this array using one single operation...

    // a) is swapping sufficient?:
    if(2 == displacementsCount)
    {
      std::cout << "yes" << std::endl
          << "swap " << firstDisplacement + 1 << " " << lastDisplacement + 1
          << std::endl;
          // took care of 1-based indexing in the line above.
    }
    else
    {
      // b) is reversing sufficient?
      //    To answer this, the part of the array is actually reversed:
      for(int n = firstDisplacement, k = lastDisplacement;
          n <= (firstDisplacement + lastDisplacement) / 2; ++n, --k)
      {
        int temp = input[n];
        input[n] = input[k];
        input[k] = temp;
      }

      if(std::is_sorted(input.begin(), input.end()))
      {
        std::cout << "yes" << std::endl
            << "reverse " << firstDisplacement + 1 << " "
            << lastDisplacement + 1 << std::endl;
            // took care of 1-based indexing in the line above as well.
      }
      else
      {
        std::cout << "no" << std::endl;
      }
    }

  }

  return 0;
}
