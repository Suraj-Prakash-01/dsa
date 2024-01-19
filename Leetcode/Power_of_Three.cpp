class Solution
{
public:
  bool isPowerOfThree(int n)
  {
    // Base condition
    if (n < 1)
      return false;
    if (n == 1)
      return true; // Base Condition
    if (n % 3 != 0)
      return false;               // It check validity after every call
    return isPowerOfThree(n / 3); // Recursive Call
  }
};