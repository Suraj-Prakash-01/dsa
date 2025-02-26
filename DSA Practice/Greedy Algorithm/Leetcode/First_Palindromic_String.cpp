class Solution
{
public:
  bool isPalindrome(string words)
  {
    int i = 0;
    int j = words.size() - 1;

    // Function to check palindrome
    while (i <= j)
    {
      if (words[i] != words[j])
        return false; // Returns false when it isn't palindrome
      i++;
      j--;
    }
    // Returns true if above function returns anything
    return true;
  }

public:
  string firstPalindrome(vector<string> &words)
  {
    // Traversing the array
    for (int i = 0; i < words.size(); i++)
    {
      // Calling function and passing each word until we finds palindrome
      if (isPalindrome(words[i]))
        return words[i];
    }
    // If nothing returned up until now, means there is no palindrome in the array
    return "";
  }
};