/*
Solution to the "FunnyString" challenge by HackerRank:
https://www.hackerrank.com/challenges/funny-string
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    std::string input;
    std::cin >> input;

    int L = input.length();
    bool isFunny = true;
    int leftDiff, rightDiff;

    for(int p = 0; ((p < L / 2 ) && isFunny); ++p)
    {
      leftDiff = std::abs(input[p] - input[p + 1]);
      rightDiff = std::abs(input[L - 1 - p] - input[L - 2 - p]);
      isFunny = (leftDiff == rightDiff);
    }

    std::cout << (isFunny ? "" : "Not ") << "Funny" << std::endl;
  }

  return 0;
}
