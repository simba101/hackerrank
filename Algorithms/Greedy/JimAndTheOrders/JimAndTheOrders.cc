/*
Solution to the "JimAndTheOrders" challenge by HackerRank:
https://www.hackerrank.com/challenges/jim-and-the-orders
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

struct Order
{
  int number;
  int delivery_time;
};

const int NMAX = 1000;
Order orders[NMAX];

void print_array(int N)
{
  for(int n = 0; n < N; ++n)
  {
    std::cout << orders[n].number << " ";
  }
  std::cout << std::endl;
}

void print_array_ex(int N)
{
  for(int n = 0; n < N; ++n)
  {
    std::cout << "{" << orders[n].number << ", " << orders[n].delivery_time
              << "}" << std::endl;
  }
  std::cout << std::endl;
}


int main(int argc, char **argv)
{
  int N, t, d;
  std::cin >> N;

  // Reads the orders (time + delivery time), processes them into the array:
  for(int n = 0; n < N; ++n)
  {
    std::cin >> t >> d;
    orders[n].number = n + 1;
    orders[n].delivery_time = t + d;
  }

  // Sorts the array in order of increasing delivery time:
  int minimum;
  Order temp;
  for(int s = 0; s < N; ++s)
  {
    minimum = s;
    for(int k = s + 1; k < N; ++k)
    {
      if(orders[k].delivery_time < orders[minimum].delivery_time)
      {
        minimum = k;
      }
    }
    temp = orders[s];
    orders[s] = orders[minimum];
    orders[minimum] = temp;
  }

  // Prints out the numbers of consecutively realized orders:
  print_array(N);
  return 0;
}
