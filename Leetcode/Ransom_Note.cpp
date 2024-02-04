class Solution
{
public:
  bool canConstruct(string ransomNote, string magazine)
  {
    // Creating an array to save frequency
    int arr[26];

    // Storing frequency of characters
    for (int i = 0; i < magazine.size(); i++)
    {
      arr[magazine[i] - 'a']++;
    }

    // Reducing frequency every time the character of ransomNote matches
    for (int i = 0; i < ransomNote.size(); i++)
    {
      arr[ransomNote[i] - 'a']--;

      // If frequency at any index, becomes -1, that means it's not available in magazine
      if (arr[ransomNote[i] - 'a'] == -1)
        return false;
    }
    return true;
  }
};