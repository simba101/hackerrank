/*
Solution to the "ArraySplitting" challenge by HackerRank:
https://www.hackerrank.com/challenges/array-splitting
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>


void print_array(std::vector<int> arr)
{
  for(int i = 0; i < arr.size(); ++i)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}


int get_score(std::vector<int> a, int previous_step_score = 0)
{
  // calculates the sum of all the elements first:
  unsigned long long sum = 0;
  for(int i = 0; i < a.size(); ++i)
  {
    sum += a[i];
  }

  // Can only evenly divide an array if the sum of its elements is even,
  // else it is impossible and previous step score should be returned.
  if (sum % 2 != 0)
  {
    return previous_step_score;
  }

  unsigned long long target_sum = sum / 2;

  // calculates at which point the array should be split:
  int splitting_position = 0;
  unsigned long long int left_sum = 0;

  while (left_sum < target_sum)
  {
    left_sum += a[splitting_position];
    splitting_position += 1;
  }



  if (left_sum == target_sum)
  {
    // partitioning can be done! Prepares two vectors representing the left
    // and the right side of an array after splitting:
    std::vector<int> left, right;

    // fills in the left array vector:
    for (int i = 0; i < splitting_position; ++i)
    {
      left.push_back(a[i]);
    }

    // fills in the right array vector:
    for (int i = splitting_position; i < a.size(); ++i)
    {
      right.push_back(a[i]);
    }

    // calculates the scores obtained by further selecting left or right array,
    // returns the greater one:
    int left_score = get_score(left, previous_step_score + 1);
    int right_score = get_score(right, previous_step_score + 1);

    return (left_score > right_score ? left_score : right_score);
  }
  else
  {
    // no further partitioning can be done with this array. Returns the
    // score obtained in the previous steps.
    return previous_step_score;
  }

}


int main(int argc, char **argv)
{
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t)
  {
    int N;
    std::cin >> N;
    std::vector<int> arr;
    arr.resize(N);

    bool are_zeroes_only = true;

    for (int n = 0; n < N; ++n)
    {
      std::cin >> arr[n];
      if (arr[n] != 0)
      {
        are_zeroes_only = false;
      }
    }

    // Corner case: if the array contains solely zeroes, the answer is
    // #_of_zeroes - 1 or simpler (array_length - 1):
    if (are_zeroes_only)
    {
      std::cout << arr.size() - 1 << std::endl;
    }
    else
    {
      std::cout << get_score(arr) << std::endl;
    }
  }

  return 0;
}
