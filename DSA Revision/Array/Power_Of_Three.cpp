// Using While Loop

class Solution
{
public:
  bool isPowerOfThree(int n)
  {
    if (n <= 0)
      return false;

    while (n % 3 == 0)
      n /= 3;

    return n == 1;
  }
};

// Using Recursion

class Solution
{
public:
  bool isPowerOfThree(int n)
  {
    if (n <= 0)
      return false;
    if (n == 1)
      return true;
    if (n % 3 != 0)
      return false;

    return isPowerOfThree(n / 3);
  }
};

// Solution 3 - Without recursion and while loop

class Solution
{
public:
  bool isPowerOfThree(int n)
  {
    // 1162261467 is 3^19,  3^20 is bigger than int
    return n > 0 && 1162261467 % n == 0;
  }
};