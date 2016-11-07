/*
Solution to the "ChiefHopper" challenge by HackerRank:
https://www.hackerrank.com/challenges/chief-hopper
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>
#include <vector>

struct Building
{
  int height;
  int energy;
};

int N;
std::vector<Building> map;

void print_all()
{
  std::cout << "Index\tLevel\tEnergy" << std::endl;
  for(int i = 0; i < map.size(); ++i)
  {
    std::cout << i << "\t" << map[i].height << "\t" << map[i].energy << std::endl;
  }
}

int main(int argc, char **argv)
{
  std::cin >> N;

  // Reads the map from the standard input:
  map.resize(N + 1);
  map[0].height = 0;
  for (int i = 1; i <= N; ++i)
  {
    std::cin >> map[i].height;
  }

  // print_all();

  // Calculates the necessary energies:
  map[N].energy = 0;
  for (int i = N; i > 0; --i)
  {
    int temp = map[i].energy + map[i].height;
    if (temp % 2 == 1)
    {
      temp += 1;
    }
    map[i - 1].energy = temp / 2;
  }

  // print_all();

  std::cout << map[0].energy << std::endl;

  return 0;
}
