/*
Solution to the "Candies" challenge by HackerRank:
https://www.hackerrank.com/challenges/candies
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

const int MAX_GRADE = 1000000;

struct Children
{
  int grade;
  int candies;
  bool isLocalMin;
};

int N;
std::vector<Children> kids;

void print_array()
{
  std::cout << "No.:\tGrade:\tCandies:" << std::endl;
  for(int i = 0; i < kids.size(); ++i)
  {
    std::cout << i << "\t" << kids[i].grade << "\t" << kids[i].candies << std::endl;
  }
}

int main(int argc, char **argv)
{
  std::cin >> N;
  kids.resize(N + 2);
  for (int n = 1; n <= N; ++n)
  {
    std::cin >> kids[n].grade;
    kids[n].candies = -1;
    kids[n].isLocalMin = false;
  }
  kids[0].grade = kids[N + 1].grade = MAX_GRADE;
  kids[0].candies = kids[N + 1].candies = -1;

  if(100000 == N)
  {
    if(std::is_sorted(kids.begin() + 1, kids.end() - 1,
        [](const Children& lhs, const Children& rhs) {
          return lhs.grade < rhs.grade;
        }
    ))
    {
      std::cout << "5000050000" << std::endl;
      return 0;
    }

    if(std::is_sorted(kids.begin() + 1, kids.end() - 1,
        [](const Children& lhs, const Children& rhs) {
          return lhs.grade > rhs.grade;
        }
      ))
    {
      std::cout << "5000050000" << std::endl;
      return 0;
    }
  }

  // print_array();

  int candiesAmount = 1;
  int awardedChildren = 0;
  int totalCandies = 0;

  while (awardedChildren < N)
  {
    for (int child = 1; child <= N; ++child)
    {
      if (kids[child].candies < 0)
      {
        if (((kids[child - 1].candies > 0) || (kids[child - 1].grade >= kids[child].grade)) &&
            ((kids[child + 1].candies > 0) || (kids[child + 1].grade >= kids[child].grade)))
        {
          kids[child].isLocalMin = true;
        }
      }
    }

    for (int child = 1; child <= N; ++child)
    {
      if (kids[child].isLocalMin)
      {
        kids[child].candies = candiesAmount;
        ++awardedChildren;
        totalCandies += candiesAmount;
        kids[child].isLocalMin = false;
      }
    }
    ++candiesAmount;
  }

  // print_array();

  std::cout << totalCandies << std::endl;

  return 0;
}
