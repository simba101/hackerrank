/*
Solution to the "Euler008" challenge by HackerRank:
https://www.hackerrank.com/contests/projecteuler/challenges/euler008
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>
#include <vector>

std::string number;
std::vector<int> digits;

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    int N, K;
    std::cin >> N >> K;
    std::cin >> number;
    digits.clear();
    for(int d = 0; d < number.size(); ++d)
    {
      int digit = static_cast<int>(number[d] - '0');
      digits.push_back(digit);
    }

    int max_product = 0;
    for(int k = 0; k <= N - K; ++k)
    {
      int product = digits[k];
      for(int i = 1; i < K; ++i)
      {
        product *= digits[k + i];
      }

      if(product > max_product)
      {
        max_product = product;
      }
    }

    std::cout << max_product << std::endl;
  }

  return 0;
}
