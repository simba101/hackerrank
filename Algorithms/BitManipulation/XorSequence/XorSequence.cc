/*
Solution to the "XorSequence" challenge by HackerRank:
https://www.hackerrank.com/challenges/xor-se
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

void print_xor_sequence()
{
  int a[32];
  int b[32];
  a[0] = 0;
  b[0] = 0;
  for(int x = 1; x < 32; ++x)
  {
    a[x] = a[x - 1] ^ x;
    b[x] = b[x - 1] ^ a[x];
    std::cout << x << ":\t" << a[x] << "\t" << b[x] << std::endl;
  }
}

long long superxor(long long x)
{
  int rem = x % 8;
  if(0 == rem || 1 == rem)
  {
    return x;
  }
  else if(2 == rem || 3 == rem)
  {
    return 2LL;
  }
  else if(4 == rem || 5 == rem)
  {
    return (x + 2LL);
  }
  else {
    // 6 == rem || 7 == rem:
    return 0LL;
  }

}

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;

  for(int t = 0; t < T; ++t)
  {
    long long int ans;
    long long int L, R;
    std::cin >> L >> R;

    ans = superxor(L - 1) ^ superxor(R);
    std::cout << ans << std::endl;
  }

  // print_xor_sequence();
  return 0;
}
