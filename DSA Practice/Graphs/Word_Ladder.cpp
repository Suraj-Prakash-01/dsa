class Solution
{
public:
  // Function to find the shortest transformation sequence length from beginWord to endWord
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {
    // Create a queue to store pairs of words and their respective step count (distance from beginWord)
    queue<pair<string, int>> q;
    // Start BFS with beginWord, initial step count is 1
    q.push({beginWord, 1});

    // Create a set from the wordList to quickly check the existence of words
    unordered_set<string> st(wordList.begin(), wordList.end());
    // Remove the beginWord from the set as we don't need to transform it
    st.erase(beginWord);

    // Start BFS traversal
    while (!q.empty())
    {
      // Get the current word and the step count (distance) from the front of the queue
      string word = q.front().first;
      int steps = q.front().second;
      q.pop();

      // If the current word matches the endWord, return the number of steps
      if (word == endWord)
        return steps;

      // Loop through each character of the current word
      for (int i = 0; i < word.size(); i++)
      {
        // Save the original character at position i
        char original = word[i];

        // Try replacing the character at position i with every letter from 'a' to 'z'
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
          word[i] = ch; // Change the character at position i

          // If the modified word exists in the set, it's a valid transformation
          if (st.find(word) != st.end())
          {
            // Erase the word from the set to prevent revisiting it
            st.erase(word);
            // Push the transformed word and the new step count into the queue
            q.push({word, steps + 1});
          }
        }
        // Restore the original character at position i for the next iteration
        word[i] = original;
      }
    }

    // If we can't reach endWord, return 0 indicating no valid transformation sequence
    return 0;
  }
};
