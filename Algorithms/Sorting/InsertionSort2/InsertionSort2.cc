/*
Solution to the "InsertionSort2" challenge by HackerRank:
https://www.hackerrank.com/challenges/insertionsort2
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>

const int NMAX = 1000;
int n;
int arr[NMAX];

void print_array()
{
  for(int i = 0; i < n; ++i)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  std::cin >> n;
  for(int i = 0; i < n; ++i)
  {
    std::cin >> arr[i];
  }

  for(int sorted = 1; sorted < n; ++sorted)
  {
    // stores the value of next element:
    int value = arr[sorted];

    // searches for the position on which sorted'th element should be put:
    int pos = 0;
    while((pos <= sorted) && (arr[sorted] > arr[pos]))
    {
      pos += 1;
    }

    // flushes the contents to the right
    // (every element in sorted part that is greated than inserted element):
    int flushing = sorted - 1;
    while(flushing >= pos)
    {
      arr[flushing + 1] = arr[flushing];
      flushing -= 1;
    }

    // inserts the [sorted] element at found position:
    arr[pos] = value;

    // prints out the state of the array at this stage of insertionsort:
    print_array();
  }

  return 0;
}
