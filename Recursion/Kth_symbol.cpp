class Solution
{
public:
  int kthGrammar(int n, int k)
  {
    if (k == 1)
      return 0;                  // since first element will always be 0
    int mid = pow(2, n - 1) / 2; // Finding mid
    if (k <= mid)
      return kthGrammar(n - 1, k); // Before mid, the output is similar to previous one
    else
      return !kthGrammar(n - 1, k - mid); // After mid, the output opposite of previous one
  }
};