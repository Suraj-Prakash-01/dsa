#include <iostream>
using std::cin;
using std::cout;

class Node
{
public:
  int data;
  Node *prev;
  Node *next;

  // Constructor
  Node(int data)
  {
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }

  ~Node()
  {
    int value = this->data;
    if (next != NULL)
    {
      delete next;
      next = NULL;
    }

    cout << "Memory free for node with data " << value << std::endl;
  }
};

// Inserting At Head
void insertAtHead(Node *&head, Node *&tail, int d)
{
  // Empty list
  Node *temp = new Node(d);
  if (head == NULL)
  {
    head = temp;
    tail = temp;
  }
  else
  {
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
}

// Insertion At Tail
void insertAtTail(Node *&head, Node *&tail, int d)
{
  Node *temp = new Node(d);
  // Empty List
  if (tail == NULL)
  {
    tail = temp;
    head = temp;
  }
  else
  {
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
}

// Inserting at a position
void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
  // Insert at Start
  if (position == 1)
  {
    insertAtHead(head, tail, d);
    return;
  }

  Node *temp = head;
  int cnt = 1;

  while (cnt < position - 1)
  {
    temp = temp->next;
    cnt++;
  }

  // Inserting at Last Position
  if (temp->next == NULL)
  {
    insertAtTail(head, tail, d);
    return;
  }

  // Creating a node for d
  Node *nodeToInsert = new Node(d);
  nodeToInsert->next = temp->next;
  temp->next->prev = nodeToInsert;
  temp->next = nodeToInsert;
  nodeToInsert->prev = temp;
}

// Deleting a node
void deleteNode(Node *&head, int position)
{
  // Deleting first or start node
  if (position == 1)
  {
    Node *temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;
    delete temp;
  }

  else
  {
    // Deleting any middle node or last node
    Node *curr = head;
    Node *prev = NULL;

    int cnt = 1;
    while (cnt < position)
    {
      prev = curr;
      curr = curr->next;
      cnt++;
    }

    curr->prev = NULL; // For the sake of destructor
    prev->next = curr->next;
    curr->next = NULL; // For the sake of destructor
    delete curr;
  }
}

// Traversing a Linked List
void print(Node *head)
{
  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << std::endl;
}

// To get length of Linked List
int getLength(Node *&head)
{
  int len = 0;

  Node *temp = head;

  while (temp != NULL)
  {
    len++;
    temp = temp->next;
  }

  return len;
}

int main()
{
  Node *node1 = new Node(10);
  Node *head = node1;
  Node *tail = node1;

  print(head);
  cout << getLength(head) << std::endl;

  insertAtHead(head, tail, 12);
  print(head);

  insertAtHead(head, tail, 15);
  print(head);

  insertAtHead(head, tail, 25);
  print(head);

  insertAtTail(head, tail, 30);
  print(head);

  insertAtPosition(head, tail, 2, 100);
  print(head);

  deleteNode(head, 1);
  print(head);
}