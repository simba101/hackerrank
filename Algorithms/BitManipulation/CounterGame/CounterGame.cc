/*
Solution to the "CounterGame" challenge by HackerRank:
https://www.hackerrank.com/challenges/counter-game
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int countSetBits(unsigned long long int in)
{
  unsigned int count = 0;
  while(in > 0)
  {
    if(1 == (in & 1))
    {
      ++count;
    }
    in >>= 1;
  }
  return count;
}

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    unsigned long long int c;
    std::cin >> c;

    int setbits = countSetBits(c - 1ULL);
    // std::cout << "Set bits: " << setbits << std::endl;
    std::cout << ((0 == (setbits % 2)) ? "Richard" : "Louise") << std::endl;
  }

  return 0;
}
