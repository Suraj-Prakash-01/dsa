// This is a class definition for a binary tree node.
struct TreeNode
{
  // The value stored in the node.
  int val;
  // Pointers to the left and right child nodes.
  TreeNode *left;
  TreeNode *right;
  // Constructor to initialize a new node with a given value.
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// This is a class definition for a codec that can serialize and deserialize binary trees.
class Codec
{
public:
  // This function serializes a binary tree into a single string.
  string serialize(TreeNode *root)
  {
    // If the tree is empty, return an empty string.
    if (!root)
      return "";

    // Initialize an empty string to store the serialized tree.
    string s = "";
    // Create a queue to store nodes to be processed.
    queue<TreeNode *> q;
    // Add the root node to the queue.
    q.push(root);
    // Process nodes in the queue until it's empty.
    while (!q.empty())
    {
      // Get the next node from the queue.
      TreeNode *curNode = q.front();
      q.pop();

      // If the node is null, append a special marker to the string.
      if (curNode == NULL)
        s.append("#,");
      // Otherwise, append the node's value to the string.
      else
        s.append(to_string(curNode->val) + ',');
      // If the node is not null, add its children to the queue.
      if (curNode != NULL)
      {
        q.push(curNode->left);
        q.push(curNode->right);
      }
    }
    // Print the serialized string to the console (for debugging purposes).
    cout << s;
    // Return the serialized string.
    return s;
  }

  // This function deserializes a string into a binary tree.
  TreeNode *deserialize(string data)
  {
    // If the input string is empty, return a null tree.
    if (data.size() == 0)
      return NULL;
    // Create a stringstream to parse the input string.
    stringstream s(data);
    // Extract the first value from the string (the root node's value).
    string str;
    getline(s, str, ',');
    // Create a new root node with the extracted value.
    TreeNode *root = new TreeNode(stoi(str));
    // Create a queue to store nodes to be processed.
    queue<TreeNode *> q;
    // Add the root node to the queue.
    q.push(root);

    // Process nodes in the queue until it's empty.
    while (!q.empty())
    {
      // Get the next node from the queue.
      TreeNode *node = q.front();
      q.pop();

      // Extract the next value from the string (the left child's value).
      getline(s, str, ',');
      // If the value is the special marker, set the left child to null.
      if (str == "#")
        node->left = NULL;
      // Otherwise, create a new left child node with the extracted value.
      else
      {
        TreeNode *leftNode = new TreeNode(stoi(str));
        node->left = leftNode;
        // Add the left child node to the queue.
        q.push(leftNode);
      }

      // Extract the next value from the string (the right child's value).
      getline(s, str, ',');
      // If the value is the special marker, set the right child to null.
      if (str == "#")
      {
        node->right == NULL;
      }
      // Otherwise, create a new right child node with the extracted value.
      else
      {
        TreeNode *rightNode = new TreeNode(stoi(str));
        node->right = rightNode;
        // Add the right child node to the queue.
        q.push(rightNode);
      }
    }
    // Return the deserialized tree.
    return root;
  }
};

// This is a comment explaining how to use the Codec class.
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;