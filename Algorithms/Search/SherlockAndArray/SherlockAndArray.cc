/*
Solution to the "SherlockAndArray" challenge by HackerRank:
https://www.hackerrank.com/challenges/sherlock-and-array
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for (int t = 0; t < T; ++t)
  {
    int N;
    std::vector<int> list;
    int val;

    std::cin >> N;
    list.reserve(N);
    for (int n = 0; n < N; ++n)
    {
      std::cin >> val;
      list.push_back(val);
    }

    // Checks the border case: first element.
    int sumLeft = 0;
    int sumRight = 0;
    for (int r = 1; r < N; ++r)
    {
      sumRight += list.at(r);
    }

    // Checks the rest of the array:
    bool found = (sumRight == 0);
    int currentlyChecked = 1;

    while ((currentlyChecked < N) && (!found))
    {
      sumLeft += list.at(currentlyChecked - 1);
      sumRight -= list.at(currentlyChecked);

      // std::cout << "Currently checked: " << currentlyChecked
      //           << "SumLeft: " << sumLeft << ", sumRight: "
      //           << sumRight << std::endl;
      found = (sumLeft == sumRight);

      ++currentlyChecked;
    }

    std::cout << (found ? "YES" : "NO") << std::endl;
  }

  return 0;
}
