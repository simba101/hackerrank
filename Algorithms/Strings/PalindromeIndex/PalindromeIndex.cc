/*
Solution to the "PalindromeIndex" challenge by HackerRank:
https://www.hackerrank.com/challenges/palindrome-index
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    std::string candidate;
    std::cin >> candidate;
    int L = candidate.length();

    // searches for the first occurrence of un-matched characters:
    int mismatch_pos = -1;
    for(int c = 0; ((c < L) && (mismatch_pos == -1)); ++c)
    {
      if(candidate[c] != candidate[L - 1 - c])
      {
        mismatch_pos = c;
      }
    }

    if(mismatch_pos == -1)
    {
      // string is a palindrome already.
      std::cout << "-1" << std::endl;
    }
    else
    {
      bool determined = false;
      bool isValidAfterDeletingLeft;
      int checking_pos = mismatch_pos;

      while(!determined)
      {
        if(candidate[checking_pos] != candidate[L - 2 - checking_pos])
        {
          // deleting the character on the right won't result in a palindrome,
          // so the one on the left should be deleted.
          isValidAfterDeletingLeft = true;
          determined = true;
        }
        else if(candidate[checking_pos + 1] != candidate[L - 1 - checking_pos])
        {
          // deleting the character on the left won't result in a palindrome,
          // so the one on the right should be deleted.
          isValidAfterDeletingLeft = false;
          determined = true;
        }
        else
        {
          // not yet determined which character to delete
          // - it should be investigated further:
          ++checking_pos;
        }
      }

      if(!isValidAfterDeletingLeft)
      {
        mismatch_pos = L - 1 - mismatch_pos;
      }

      std::cout << mismatch_pos << std::endl;
    }

  }

  return 0;
}
