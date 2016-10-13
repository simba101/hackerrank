/*
Solution to the "AngryProfessor" challenge by HackerRank:
https://www.hackerrank.com/challenges/angry-professor
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T, t, n, k, onTime, arrivalTime;

  std::cin >> T;
  for(int t = 0; t < T; ++t)
  {
    onTime = 0;
    std::cin >> n >> k;

    for(int i = 0; i < n; ++i)
    {
      std::cin >> arrivalTime;
      if(arrivalTime <= 0)
      {
        ++onTime;
      }
    }

    std::cout << (onTime >= k ? "NO" : "YES") << std::endl;
  }

  return 0;
}
