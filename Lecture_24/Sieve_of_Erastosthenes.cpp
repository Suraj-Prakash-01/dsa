class Solution
{
public:
  int countPrimes(int n)
  {
    int cnt = 0;
    // To create an array with all element as true
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = 0;

    for (int i = 2; i < n; i++)
    {
      if (prime[i])
      {
        cnt++;
        // To sieve out multiples of prime
        for (int j = 2 * i; j < n; j += i)
          prime[j] = 0;
      }
    }
    return cnt;
  }
};