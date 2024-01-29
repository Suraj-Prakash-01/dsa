class Solution
{
public:
  bool isHappy(int n)
  {
    // Base Condition
    if (n < 10)
    {
      if (n == 1 || n == 7)
        return true;
      return false;
    }

    // Temporary Variable
    int temp = 0;
    int sum = 0;
    // Loop to find the square of remainders
    while (n > 0)
    {
      sum = n % 10;
      temp += sum * sum;
      n /= 10;
    }

    // Recursive Call
    return isHappy(temp);
  }
};