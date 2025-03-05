// Using recursion for find answers

class Solution
{
public:
  long long coloredCells(int n)
  {
    if (n == 1)
      return 1;
    return (n - 1) * 4 + coloredCells(n - 1);
  }
};

// consider 2 triangle-like areas (orange+yellow, yellow+blue)
// 1 of both is (2n+1+1)*n/2 (Arithmetic progression)
// their intersection is (2n+1) (yellow)
// so ans=2*(n+1)n-(2n+1)=2*n*(n-1)+1

class Solution
{
public:
  long long coloredCells(int n)
  {
    return 2LL * n * (n - 1) + 1;
  }
};