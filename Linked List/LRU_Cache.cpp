// We will solve this problem using map and doubly linked list
// We will store the key and address of the node in the map
// We keep on inserting new element after head and automatically the least recently used element shifts to the last

class LRUCache
{
public:
  // Class for initializing a doubly linked list
  class node
  {
  public:
    int key;    // Key of the node
    int val;    // Value of the node
    node *next; // Pointer to the next node
    node *prev; // Pointer to the previous node

    node(int key, int val)
    {
      this->key = key;
      this->val = val;
    }
  };

  // Initializing head and tail of the linked list
  node *head = new node(-1, -1); // Head node
  node *tail = new node(-1, -1); // Tail node

  int cnt;
  // Initializing map
  unordered_map<int, node *> m; // Map to store the nodes

  // Constructor to initialize the cache with a given capacity
  LRUCache(int capacity)
  {
    cnt = capacity;
    head->next = tail;
    tail->prev = head;
  }

  // Function to add a new node after the head
  void addNode(node *newnode)
  {
    node *temp = head->next;

    newnode->next = temp;
    newnode->prev = head;

    head->next = newnode;
    temp->prev = newnode;
  }

  // Function to delete a node from the linked list
  void deleteNode(node *delnode)
  {
    node *delprev = delnode->prev;
    node *delnext = delnode->next;

    delprev->next = delnext;
    delnext->prev = delprev;
  }

  // Function to return the value of a key if it is available
  int get(int key)
  {
    // If the key is found
    if (m.find(key) != m.end())
    {
      node *resnode = m[key]; // Storing the node
      int res = resnode->val; // Storing the value of the node
      m.erase(key);           // Removing the found node from the map
      deleteNode(resnode);    // Deleting node from the linked list
      addNode(resnode);       // Adding the same node in the front
      m[key] = head->next;    // Updating the map
      return res;             // Returning the value
    }
    return -1; // Returning -1 if the key is not found
  }

  // Function to put a new key-value pair in the cache
  void put(int key, int value)
  {
    // If the key is already present in the cache
    if (m.find(key) != m.end())
    {
      node *existingnode = m[key];
      m.erase(key);             // Removing the existing node from the map
      deleteNode(existingnode); // Deleting the existing node from the linked list
    }

    // If the cache is full
    if (m.size() == cnt)
    {
      m.erase(tail->prev->key); // Removing the least recently used node from the map
      deleteNode(tail->prev);   // Deleting the least recently used node from the linked list
    }

    addNode(new node(key, value)); // Adding the new node in the front
    m[key] = head->next;           // Updating the map
  }
};
