/*
Solution to the "s10_day4_binomial_distribution_2" challenge by HackerRank:
https://www.hackerrank.com/challenges/s10-binomial-distribution-2
Written on 28-11-2016 in C++14
by simba (szczerbiakadam@gmail.com)
License: MIT
*/


#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>


// Returns a factorial (n!) of a number provided as a parameter.
unsigned long long int factorial(unsigned int n)
{
  unsigned long long int result = 1ULL;
  for(unsigned long long int i = 2; i <= n; ++i)
  {
    result *= i;
  }

  return result;
}

// Returns the value of (n!) / ( (k!) * ((n - k)!)).
unsigned long long int n_choose_k(unsigned int n, unsigned int k)
{
  return (factorial(n) / (factorial(k) * factorial(n - k)));
}

double get_binomial_probability(unsigned int n, unsigned int k,
    double success_prob)
{
  return (static_cast<double>(n_choose_k(n, k)) * (std::pow(success_prob, k)) *
      (std::pow(1 - success_prob, n - k)));
}

int main(int argc, char **argv)
{
  // Reads the data: the probability of a piston being defective
  // (represented as an integer in range (0, 100) exclusively),
  // and the size of a batch, as integer:
  int failure_probability_percent;
  int batch_size;
  std::cin >> failure_probability_percent >> batch_size;
  double failure_probability = failure_probability_percent / 100.0;

  // calculates the  probability that there will be exactly K defective items
  // in the batch of N items:
  std::vector<double> probabilities;
  probabilities.resize(batch_size + 1);

  for(int k = 0; k <= batch_size; ++k)
  {
    probabilities[k] =
        get_binomial_probability(batch_size, k, failure_probability);
  }

  // Calculates the answers the following questions:
  // what is the probability that the batch will contain no more than 2 rejects?
  double good_batch_prob =
      probabilities[0] + probabilities[1] + probabilities[2];

  // what is the probability that the batch will contain at least 2 rejects?
  double bad_batch_prob = 0.0;
  for(int i = 2; i <= batch_size; ++i)
  {
    bad_batch_prob += probabilities[i];
  }

  // Prints out the answers:
  std::cout << std::setprecision(3) << std::fixed;
  std::cout << good_batch_prob << std::endl << bad_batch_prob << std::endl;


  return 0;
}
