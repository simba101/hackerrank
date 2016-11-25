/*
Solution to the "BetweenTwoSets" challenge by HackerRank:
https://www.hackerrank.com/challenges/between-two-sets
Written on 24-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <vector>


/// Returns the greatest common divisor of two integer values:
int gcd(int a, int b)
{
  int temp;
  while(b > 0)
  {
    temp = b;
    b = a % b;
    a = temp;
  }

  return a;
}

/// Returns the greatest common divisor of a set of integer values:
int gcd(std::vector<int> data)
{
  int result = data[0];
  for(int i = 1; i < data.size(); ++i)
  {
    result = gcd(data[i], result);
  }

  return result;
}

/// Returns the lowest common multiple of two integer values:
int lcm(int a, int b)
{
  return (a * b) / gcd(a, b);
}

/// Returns the lowest common multiple of a set of integer values:
int lcm(std::vector<int> data)
{
  int result = data[0];
  for(int i = 1; i < data.size(); ++i)
  {
    result = lcm(data[i], result);
  }

  return result;
}

int main(int argc, char **argv)
{
  int setALength, setBLength;
  std::cin >> setALength >> setBLength;

  std::vector<int> setA(setALength);
  std::vector<int> setB(setBLength);

  // reads the factors in set A:
  for(int i = 0; i < setALength; ++i)
  {
    std::cin >> setA[i];
  }

  // reads the numbers of set B:
  for(int i = 0; i < setBLength; ++i)
  {
    std::cin >> setB[i];
  }

  // calculates the least common multiple of all the numbers in set A.
  // It is the lowest value to divide all the numbers from A evenly.
  int lcm_of_A = lcm(setA);

  // calculates the greatest common divisor of all the numbers in set B.
  // It is the biggest possible value to divide all the numbers from B evenly.
  int gcd_of_B = gcd(setB);

  int multiplicator = 1;
  int answer = 0; // holds how many elements are between the two sets.

  while(lcm_of_A * multiplicator <= gcd_of_B)
  {
    if(gcd_of_B % (lcm_of_A * multiplicator) == 0)
    {
      answer += 1;
    }

    multiplicator += 1;
  }

  std::cout << answer << std::endl;

  return 0;
}
