/*
Solution to the "InsertionSort1" challenge by HackerRank:
https://www.hackerrank.com/challenges/insertionsort1
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

const int ARR_DIM = 1000;
int arr[ARR_DIM];

void print_array(int dim)
{
  for(int i = 0; i < dim; ++i)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  int n, k;
  std::cin >> n;
  int last;

  for(int i = 0; i < n; ++i)
  {
    std::cin >> arr[i];
  }

  last = arr[n - 1];
  k = n - 2;
  while(arr[k] > last) {
    arr[k + 1] = arr[k];
    print_array(n);
    k -= 1;
  }
  arr[k + 1] = last;
  print_array(n);

  return 0;
}
