/*
Solution to the "StockMaximize" challenge by HackerRank:
https://www.hackerrank.com/challenges/stockmax
by simba (szczerbiakadam@gmail.com).
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


long long prices[50000];


int main() {
    int T;
    std::cin >> T;
    for(int t = 0; t < T; ++t)
    {
        int N;
        std::cin >> N;
        for(int n = 0; n < N; ++n)
        {
            std::cin >> prices[n];
        }

        // there are three main pointers:
        int currDay = 0; // points to the currently analyzed "day",
        int hopper = 0; // for scanning the array
        int localMax = 0;

        long long totalProfit = 0;
        long long ownedShares = 0;

        while(currDay < N)
        {
            // finds next max price - will sell all stocks on that day.
            localMax = currDay;
            hopper = currDay + 1;
            while(hopper < N)
            {
                if(prices[hopper] > prices[localMax])
                {
                    localMax = hopper;
                }
                hopper += 1;
            }

            if(localMax == currDay)
            {
                // Does not buy stock on this day, forwards 1 day not doing anything:
                currDay += 1;
            }
            else
            {
                // fast-forwards to the day of local max, buying stocks each day:
                while(currDay < localMax)
                {
                    ownedShares += 1;
                    totalProfit -= prices[currDay];
                    currDay += 1;
                }
                // Sells all owned stocks:
                totalProfit += (ownedShares * prices[currDay]);
                ownedShares = 0;
                currDay += 1;
            }

            // After one round of buying & selling (or waiting)
            // updates the pointers:
            localMax = currDay;
            hopper = currDay + 1;
        }

        std::cout << totalProfit << std::endl;
    }
    return 0;
}

