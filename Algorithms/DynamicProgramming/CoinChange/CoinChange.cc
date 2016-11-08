/*
Solution to the "CoinChange" challenge by HackerRank:
https://www.hackerrank.com/challenges/coin-change
by simba (szczerbiakadam@gmail.com).
*/

#include <iostream>

const int MAX_COINS = 50;
const int MAX_SUM = 250;

unsigned long long table[MAX_SUM + 1][MAX_COINS];

unsigned long long dp_count(int coins[], int noOfCoins, int targetSum)
{
    // Fills in the entries for the "targetSum == 0" degenerate case:
    for(int i = 0; i < noOfCoins; ++i)
    {
        table[0][i] = 1ULL;
    }

    // Going bottom-up, fills in the rest of the table entries:
    for(int s = 1; s <= targetSum; ++s)
    {
        for(int c = 0; c < noOfCoins; ++c)
        {
            // Calculates the number of solutions that include coins[c]:
            unsigned long long inc = (s - coins[c] >= 0) ? table[s - coins[c]][c] : 0ULL;

            // Calculates the number of solutions that exclude coins[c]:
            unsigned long long exc = (c > 0) ? table[s][c - 1] : 0ULL;

            table[s][c] = inc + exc;
        }
    }

    return table[targetSum][noOfCoins - 1];
}

int main() {
    int cc, ts;
    int c[MAX_COINS];

    std::cin >> ts >> cc;
    for(int i = 0; i < cc; ++i)
    {
        std::cin >> c[i];
    }

    unsigned long long ans = dp_count(c, cc, ts);

    std::cout << ans << std::endl;

    return 0;
}
