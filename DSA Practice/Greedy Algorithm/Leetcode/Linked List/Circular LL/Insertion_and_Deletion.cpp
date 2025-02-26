#include <iostream>
using std::cin;
using std::cout;

class Node
{
public:
  int data;
  Node *next;

  // Constructor
  Node(int d)
  {
    this->data = d;
    this->next = NULL;
  }

  ~Node()
  {
    int val = this->data;
    if (this->next != NULL)
    {
      delete next;
      next = NULL;
    }

    cout << "Memory is free for node with data " << val << std::endl;
  }
};

// Insertion at Head
void insertNode(Node *&tail, int element, int d)
{
  // Empty List
  if (tail == NULL)
  {
    Node *newNode = new Node(d);
    tail = newNode;
    newNode->next = newNode;
  }

  else
  {
    // Non Empty List
    // Assuming that the element is present in the List

    Node *curr = tail;

    // element is like a key value
    while (curr->data != element)
    {
      curr = curr->next;
    }

    // Element found -> curr is representing the node containing the element
    Node *temp = new Node(d);
    temp->next = curr->next;
    curr->next = temp;
  }
}

// Deleting a node
void deleteNode(Node *&tail, int element)
{
  // Empty List
  if (tail == NULL)
  {
    cout << " List is empty" << std::endl;
    return;
  }

  else
  {
    // Non Empty list
    // Assuming that "value" is present in the Linked List

    Node *prev = tail;
    Node *curr = prev->next;

    while (curr->data != element)
    {
      prev = curr;
      curr = curr->next;
    }

    prev->next = curr->next;

    // 1 node Linked List
    if (curr == prev)
    {
      tail = NULL;
    }

    // >=2 Node Linked List
    if (tail == curr)
    {
      tail = prev;
    }
    curr->next = NULL;
    delete curr;
  }
}

// Traversing in the Linked List
void print(Node *&tail)
{
  Node *temp = tail;

  // Empty List
  if (tail == NULL)
  {
    cout << "List is empty" << std::endl;
    return;
  }

  do
  {
    cout << temp->data << " ";
    temp = temp->next;
  } while (temp != tail);

  cout << std::endl;
}

int main()
{
  Node *tail = NULL;

  // Inserting in empty list
  insertNode(tail, 5, 3);
  print(tail);

  insertNode(tail, 3, 8);
  print(tail);

  insertNode(tail, 3, 12);
  print(tail);

  deleteNode(tail, 3);
  print(tail);
}