
// Total number of undirected graphs that can be formed with n edges is 2 to the power n*(n-1)/2
// i.e. pow(2,n*(n-1)/2)

class Solution
{
public:
  long long count(int n)
  {
    // 1 LL << is equal to 2 to the power.....
    long long ans = 1LL << n * (n - 1) / 2;
    return ans;
  }
};