class Solution
{
  // A map to store the minimum number of steps (shortest path) to reach each word.
  unordered_map<string, int> mp;

  // A 2D vector to store all possible sequences (paths) that transform `beginWord` to `endWord`.
  vector<vector<string>> ans;

  // A string to store the `beginWord`, which will be used in DFS to check the base case.
  string b;

private:
  // Depth-first search (DFS) to backtrack and find all the valid sequences that transform `beginWord` to `endWord`.
  void dfs(string word, vector<string> &seq)
  {
    // If the current word is the `beginWord`, reverse the sequence and add it to the answer.
    if (word == b)
    {
      reverse(seq.begin(), seq.end()); // Reverse the sequence to correct the order.
      ans.push_back(seq);              // Add the current valid sequence to the results.
      reverse(seq.begin(), seq.end()); // Re-reverse the sequence to backtrack.
      return;
    }

    // Get the number of steps (distance) to the current word.
    int steps = mp[word];
    int size = word.size(); // Get the length of the word.

    // Try changing each character of the word to find its neighboring words.
    for (int i = 0; i < size; i++)
    {
      char original = word[i]; // Store the original character at position `i`.

      // Try all possible characters from 'a' to 'z'.
      for (char ch = 'a'; ch <= 'z'; ch++)
      {
        word[i] = ch; // Replace the character at index `i` with the new character `ch`.

        // If the modified word is in `mp` and it was reached in one less step, continue DFS.
        if (mp.find(word) != mp.end() && mp[word] + 1 == steps)
        {
          seq.push_back(word); // Add the word to the current sequence.
          dfs(word, seq);      // Recursively perform DFS for the next word.
          seq.pop_back();      // Backtrack by removing the word from the sequence.
        }
      }

      word[i] = original; // Restore the original character before moving to the next index.
    }
  }

public:
  // The main function to find all the shortest transformation sequences from `beginWord` to `endWord`.
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
  {
    queue<string> q;   // Queue for BFS to find the shortest paths.
    q.push(beginWord); // Start BFS from `beginWord`.

    int size = beginWord.size(); // Store the length of the word.
    b = beginWord;               // Store the `beginWord` for later use in DFS.

    // Create a set of words from the wordList to check the existence of words efficiently.
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord); // Remove the `beginWord` from the set since we have already processed it.

    mp[beginWord] = 1; // Initialize the step count for `beginWord` as 1.

    // Perform BFS to find the shortest paths from `beginWord` to `endWord`.
    while (!q.empty())
    {
      string word = q.front(); // Get the front word in the queue.
      int steps = mp[word];    // Get the number of steps to reach this word.
      q.pop();                 // Remove the word from the queue.

      // If the current word is the `endWord`, stop the BFS.
      if (word == endWord)
      {
        break;
      }

      // Try changing each character of the word.
      for (int i = 0; i < size; i++)
      {
        char original = word[i]; // Store the original character.

        // Try all possible characters from 'a' to 'z' for this position.
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
          word[i] = ch; // Replace the character at index `i` with `ch`.

          // If the modified word is in the set `st`, it is a valid transformation.
          if (st.find(word) != st.end())
          {
            q.push(word);         // Add the word to the queue for BFS.
            st.erase(word);       // Erase the word from the set to avoid revisiting.
            mp[word] = steps + 1; // Update the step count for the modified word.
          }
        }

        word[i] = original; // Restore the original character for the next index.
      }
    }

    // After BFS, if the `endWord` was found in the map, it means a path exists.
    if (mp.find(endWord) != mp.end())
    {
      vector<string> seq;     // Vector to store the current sequence of words.
      seq.push_back(endWord); // Start the sequence with `endWord`.
      dfs(endWord, seq);      // Perform DFS to backtrack and find all valid sequences.
    }

    // Return the list of all shortest transformation sequences.
    return ans;
  }
};
