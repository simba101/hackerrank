/*
Solution to the "BeautifulTriplets" challenge by HackerRank:
https://www.hackerrank.com/challenges/beautiful-triplets
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>

int countBeautifulPairs(const std::vector<int>& data, int d)
{
  int ans = 0;
  for(int k = 0; k < data.size(); ++k)
  {
    if(
        (std::find(data.begin(), data.end(), data[k] + d) != data.end()) &&
        (std::find(data.begin(), data.end(), data[k] + d + d) != data.end())
      )
    {
      ans += 1;
    }
  }

  return ans;
}

int main(int argc, char **argv)
{
  std::vector<int> data;
  int count, difference;
  std::cin >> count >> difference;
  data.resize(count);
  for(int n = 0; n < count; ++n)
  {
    std::cin >> data[n];
  }

  int bp = countBeautifulPairs(data, difference);
  std::cout << bp << std::endl;

  return 0;
}
