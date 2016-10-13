#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char **argv)
{
  std::string input;
  std::cin >> input;

  char output[9];
  output[8] = '\0';

  // Re-writes the  hh:mm:ss part:
  output[2] = input[2];
  output[3] = input[3];
  output[4] = input[4];
  output[5] = input[5];
  output[6] = input[6];
  output[7] = input[7];

  int hour = (10 * (input[0] - '0')) + (input[1] - '0');
  hour = hour % 12;

  if ('P' == input[8])
  {
    hour += 12;
  }

  output[0] = (hour / 10) + '0';
  output[1] = (hour % 10) + '0';

  std:: cout << output << std::endl;

  return 0;
}
