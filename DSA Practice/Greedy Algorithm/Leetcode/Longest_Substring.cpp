/*  ---------- Approach 1 ----------*/

class Solution
{
public:
     // Public member functions
      int
      lengthOfLongestSubstring(string s)
  {
    int n = s.length();
      int maxLength = 0;
       // Initialize the variable to store the maximum length of the substring without repeating characters
        unordered_set<char>
            charSet;
       // Initialize an unordered set to store the characters in the current substring
        int left = 0;
       // Initialize the variable to store the index of the left end of the current substring

        for (int right = 0; right < n; right++)   // Iterate through the input string
    {
      if (charSet.count(s[right]) == 0)
           // If the current character is not in the set
        {
          charSet.insert(s[right]);
             // Insert the current character into the set
              maxLength = max(maxLength, right - left + 1);
             // Update the maximum length of the substring without repeating characters
        }
      else
           // If the current character is already in the set
        {
          while (charSet.count(s[right]))
               // Move the left pointer to the right until the repeating character is removed from the set
            {
              charSet.erase(s[left]);
                 // Remove the leftmost character from the set
                  left++;
                 // Move the left pointer to the right
            }
          charSet.insert(s[right]);
             // Insert the current character into the set
        }
    }

    return maxLength;
       // Return the maximum length of the substring without repeating characters
  }
};

/*  ---------- Approach 2 ----------*/

class Solution
{
public:
  int lengthOfLongestSub(string s)
  {
    // Create an unordered_map 'm' to store the recent occurrence index
    // of each character in the string
    unordered_map<char, int> m;

    // 'n' stores the size of the input string
    int n = s.size();

    // Initialize two pointers 'i' and 'j' to traverse the string
    int i = 0, j = 0;

    // 'ans' stores the length of the longest substring without repeating characters
    int ans = 0;

    // Traverse the string 's' with pointer 'j'
    while (j < n)
    {
      // If the character at index 'j' is found in the 'm' map
      while (m[s[j]] != 0)
      {
        // Decrease the value at index 'i' in the 'm' map
        // indicating that the character at index 'i' has been processed
        m[s[i++]]--;
      }

      // Increase the value at index 'j' in the 'm' map
      // indicating that the character at index 'j' has been processed
      m[s[j]]++;

      // Update 'ans' with the maximum length between the current length
      // of the substring without repeating characters (j - i + 1)
      // and the previous value of 'ans'
      ans = max(ans, j - i + 1);

      // Move the pointer 'j' to the next index
      j++;
    }

    // Return the length of the longest substring without repeating characters
    return ans;
  }
};