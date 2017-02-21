#!/usr/bin/env python3

COLLATZ_SIZE = 5000000 + 5
collatz = [0] * COLLATZ_SIZE
answers = [0] * COLLATZ_SIZE

for k in range(23):
    collatz[2 ** k] = k

def calculate_collatz(N):
    global collatz;
    steps = 0
    n = N

    # Answers for n < N have been calculated already.
    while (n >= N):
        steps += 1
        n = (n // 2) if (n % 2 == 0) else (3 * n + 1)

    collatz[N] = collatz[n] + steps

    # Fills in the chain, until COLLATZ_SIZE is exceeded:
    steps = collatz[N]
    m = 2 * N
    while (m < COLLATZ_SIZE):
        steps += 1
        collatz[m] = steps
        m *= 2


# Precalculates the collatz sequences:
for k in range(2, COLLATZ_SIZE):
    if(collatz[k] == 0):
        calculate_collatz(k)

# Precalculates the answers: number <= k yielding the longest chain.
answers[1] = collatz[1] # should be calculated to "0".
for k in range(2, COLLATZ_SIZE):
    answers[k] = k if (collatz[k] >= collatz[answers[k-1]]) else answers[k-1]

T = int(input())
for t in range(T):
    q = int(input())
    print(answers[q])
