/*
Solution to the "BiggerIsGreater" challenge by HackerRank:
https://www.hackerrank.com/challenges/bigger-is-greater
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    std::string text;
    std::cin >> text;
    
    if(text.length() == 1)
    {
      // a string of length 1 will not have a next lexical permutation.
      std::cout << "no answer" << std::endl;
    }
    else
    {
      // searching for the pivot point:
      int pivot = text.length() - 2;
      int suffix_length = 1;
      while((pivot >= 0) && (text[pivot] >= text[pivot + 1]))
      {
        pivot -= 1;
        suffix_length += 1;
      }

      // if pivot == -1, there is no next lexical permutation.
      if(pivot == -1)
      {
        std::cout << "no answer" << std::endl;
      }
      else
      {
        // finds rightmost successor to the pivot:
        int successor = text.length() - 1;
        while(text[successor] <= text[pivot])
        {
          successor -= 1;
        }

        // swaps successor and pivot:
        char temp = text[pivot]; 
        text[pivot] = text[successor];
        text[successor] = temp;
        
        // inverts suffix:
        for(int i = 0; i < suffix_length / 2; ++i)
        {
          temp = text[pivot + 1 + i];
          text[pivot + 1 + i] = text[text.length() - 1 - i];
          text[text.length() - 1 - i] = temp;
        }

        // prints out the next lexical successor:
        std::cout << text << std::endl;
      }
    }
    
  }

  return 0;
}
