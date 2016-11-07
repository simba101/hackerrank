/*
Solution to the "LuckBalance" challenge by HackerRank:
https://www.hackerrank.com/challenges/luck-balance
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
  int N, K;
  std::cin >> N >> K;

  std::vector<int> contests;
  std::vector<int> importantContests;

  int nextLuck, nextImportance;

  for(int n = 0; n < N; ++n)
  {
    std::cin >> nextLuck >> nextImportance;
    if(0 == nextImportance)
    {
      contests.push_back(nextLuck);
    }
    else
    {
      importantContests.push_back(nextLuck);
    }
  }

  // Since at most K important contests may be failed,
  // Let Alice fail those most luck-bringing:
  std::sort(importantContests.begin(), importantContests.end(),
      std::greater<int>());

  // The luck is counted up finally:
  int luck = 0;
  for(auto it = contests.begin(); it != contests.end(); ++it)
  {
    luck += *it;
  }

  for(int i = 0; i < importantContests.size(); ++i)
  {
    if(i < K)
    {
      // Alice should fail K most-lucky contests:
      luck += importantContests[i];
    }
    else
    {
      // Tough luck, Alice, you have to pass this!
      luck -= importantContests[i];
    }
  };

  std::cout << luck << std::endl;

  return 0;
}
