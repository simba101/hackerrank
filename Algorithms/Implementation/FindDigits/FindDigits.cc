/*
Solution to "Find Digits" challenge by HackerRank
https://www.hackerrank.com/challenges/find-digits
by simba (szczerbiakadam@gmail.com)
*/

#include <iostream>

int digits[10];
bool divides[10];

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  divides[0] = false;
  divides[1] = true;

  for(int t = 0; t < T; ++t)
  {
    int N;
    std::cin >> N;

    int oldN = N;

    int digit = 0;
    int dividingDigits = 0;

    while(N > 0)
    {
      // std::cout << "Before, N = " << N << std::endl;
      digits[digit] = N % 10;
      // std::cout << "Extracted digit: " << digits[digit] << std::endl;
      N -= digits[digit];
      N /= 10;
      ++digit;
      // std::cout << "After, N = " << N << std::endl;
    }

    for(int d = 2; d < 10; ++d)
    {
      divides[d] = (oldN % d == 0);
    }

    for(int d = 0; d < digit; ++d)
    {
      // std::cout << "d = " << d << ", oldN = " << oldN << std::endl;
      if(divides[digits[d]])
      {
        ++dividingDigits;
        // std::cout << oldN << " is divisible by " << digits[d] << std::endl;
      }
    }

    std::cout << dividingDigits << std::endl;
  }

  return 0;
}
