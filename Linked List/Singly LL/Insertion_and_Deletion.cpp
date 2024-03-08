#include <iostream>
using std::cin;
using std::cout;

class Node
{
public:
  int data;
  Node *next;

  // Constructor
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }

  ~Node()
  {
    int value = this->data;

    // Memory Free
    if (this->next != NULL)
    {
      delete next;
      this->next = NULL;
    }

    cout << "Memory is free for node with data " << value << std::endl;
  }
};

// Insertion at head
void InsertionAtHead(Node *&head, int d)
{
  // New Node Creation
  Node *temp = new Node(d);
  temp->next = head;
  head = temp;
}

// Insertion at Tail
void insertionAtTail(Node *&tail, int d)
{
  // New node creation
  Node *temp = new Node(d);
  tail->next = temp;
  tail = tail->next;
}

// Inserting at Position
void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

  // Inserting at start
  if (position == 1)
  {
    InsertionAtHead(head, d);
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
    insertionAtTail(tail, d);
    return;
  }

  // Creating a node for d
  Node *nodeToInsert = new Node(d);

  nodeToInsert->next = temp->next;
  temp->next = nodeToInsert;
}

// Deleting Node
void deleteNode(Node *&head, int position)
{
  // Deleting First or Start Node
  if (position == 1)
  {
    Node *temp = head;
    head = head->next;
    temp->next = NULL;

    // Memory free start node
    delete temp;
  }

  else
  {
    Node *curr = head;
    Node *prev = NULL;

    int cnt = 1;
    while (cnt < position)
    {
      prev = curr;
      curr = curr->next;
      cnt++;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }
}

// Traversal
void print(Node *&head)
{
  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << std::endl;
}

int main()
{
  Node *node1 = new Node(10);
  cout << node1->data << std::endl;
  cout << node1->next << std::endl;

  // Head pointed to node1
  Node *head = node1;
  // print(head);

  // InsertionAtHead(head, 12);
  // print(head);

  // InsertionAtHead(head, 15);
  // print(head);

  // cout << "After Insertion at tail" << std::endl;

  Node *tail = node1;
  print(head);

  insertionAtTail(tail, 12);
  print(head);

  insertionAtTail(tail, 15);
  print(head);

  insertAtPosition(tail, head, 3, 22);
  print(head);

  cout << "Head " << head->data << std::endl;
  cout << "Tail " << tail->data << std::endl;

  deleteNode(head, 4);
  print(head);
}