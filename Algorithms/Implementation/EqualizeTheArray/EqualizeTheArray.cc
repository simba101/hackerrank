/*
Solution to the "EqualizeTheArray" challenge by HackerRank:
https://www.hackerrank.com/challenges/equality-in-a-array
Written on 24-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>


const int MIN_N = 1;
const int MAX_N = 100;
const int MAX_ITEMS = 100;

int histogram[MAX_N + 1] = {0};

int main(int argc, char **argv)
{
  // Reads in the length of the array:
  int N;
  std::cin >> N;

  // Reads in the N numbers and generates a histogram of scanned values:
  for(int n = 0; n < N; ++n)
  {
    int num;
    std::cin >> num;
    histogram[num] += 1;
  }

  // Finds the most frequent entry - how many times did it occur:
  int max = histogram[1];
  for(int k = 2; k <= MAX_N; ++k)
  {
    if(histogram[k] > max)
    {
      max = histogram[k];
    }
  }

  // Prints the number of required deletions which is the total count
  // of all the other numbers:
  std::cout << (N - max) << std::endl;

  return 0;
}
