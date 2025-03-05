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