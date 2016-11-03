/*
Solution to the "MatrixLayerRotation" challenge by HackerRank:
https://www.hackerrank.com/challenges/matrix-rotation-algo
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

int main(int argc, char **argv)
{
  const int M_MAX = 300;
  const int N_MAX = 300;

  int original[M_MAX][N_MAX];
  int rotated[M_MAX][N_MAX];
  int flatring[(2 * M_MAX) + (2 * N_MAX)];
  int flatringlength;

  int M, N, R;
  std::cin >> M >> N >> R;

  for(int y = 0; y < M; ++y)
  {
    for(int x = 0; x < N; ++x)
    {
      std::cin >> original[y][x];
    }
  }

/*
  std::cout << "Original:" << std::endl;
  for(int y = 0; y < M; ++y)
  {
    for(int x = 0; x < N; ++x)
    {
      std::cout << original[y][x] << " ";
    }
    std::cout << std::endl;
  }
  */

  int rings = ((M < N) ? M : N) / 2;

  for(int ring = 0; ring < rings; ++ring)
  {
    // calculates the length of this flat ring:
    flatringlength = 2 * ((M - (2 * ring)) + (N - (2 * (ring + 1))));
    // std::cout << "Calculated flat ring length: " << flatringlength << std::endl;

    int currentFRpos = 0;
    // flattens this ring - processes the top part:
    for(int x = ring; x < N - ring; ++x)
    {
      flatring[currentFRpos] = original[ring][x];
      ++currentFRpos;
    }

    // flattens this ring - processes the right part:
    for(int y = ring + 1; y < M - ring - 1; ++y)
    {
      flatring[currentFRpos] = original[y][N - ring - 1];
      ++currentFRpos;
    }

    // flattens this ring - processes the bottom part:
    for(int x = N - ring - 1; x >= ring; --x)
    {
      flatring[currentFRpos] = original[M - ring - 1][x];
      ++currentFRpos;
    }

    // flattens this ring - processes the left part:
    for(int y = M - ring - 2; y > ring; --y)
    {
      flatring[currentFRpos] = original[y][ring];
      ++currentFRpos;
    }

    // calculates the element that would take top-left place's index:
    currentFRpos = R % flatringlength;

    /*
    std::cout << "Flatted ring: ";
    for(int i = 0; i < flatringlength; ++i)
    {
      std::cout << flatring[i] << " ";
    }
    std::cout << std::endl;
    */

    // links rotated flatring - the top part:
    for(int x = ring; x < N - ring; ++x)
    {
      // std::cout << "T: rotated[" << ring << "][" << x << "] = flatring["
          // << currentFRpos << "] (" << flatring[currentFRpos] << ")" << std::endl;
      rotated[ring][x] = flatring[currentFRpos];
      ++currentFRpos;
      currentFRpos %= flatringlength;
    }

    // links rotated flatring - the right part:
    for(int y = ring + 1; y < M - ring - 1; ++y)
    {
      // std::cout << "R: rotated[" << y << "][" << N - ring - 1 << "] = flatring["
          // << currentFRpos << "] (" << flatring[currentFRpos] << ")" << std::endl;
      rotated[y][N - ring - 1] = flatring[currentFRpos];
      ++currentFRpos;
      currentFRpos %= flatringlength;
    }

    // links rotated flatring - the bottom part:
    for(int x = N - ring - 1; x >= ring; --x)
    {
      // std::cout << "B: rotated[" << M - ring - 1 << "][" << x << "] = flatring["
          // << currentFRpos << "] (" << flatring[currentFRpos] << ")" << std::endl;
      rotated[M - ring - 1][x] = flatring[currentFRpos];
      ++currentFRpos;
      currentFRpos %= flatringlength;
    }

    // links rotated flatring - the left part:
    for(int y = M - ring - 2; y > ring; --y)
    {
      // std::cout << "L: rotated[" << y << "][" << ring << "] = flatring["
          // << currentFRpos << "] (" << flatring[currentFRpos] << ")" << std::endl;
      rotated[y][ring] = flatring[currentFRpos];
      ++currentFRpos;
      currentFRpos %= flatringlength;
    }
  }

  for(int y = 0; y < M; ++y)
  {
    for(int x = 0; x < N; ++x)
    {
      std::cout << rotated[y][x] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
