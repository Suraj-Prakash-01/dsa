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
  print(head);

  InsertionAtHead(head, 12);
  print(head);

  InsertionAtHead(head, 15);
  print(head);

  cout << "After Insertion at tail" << std::endl;

  Node *tail = node1;
  print(head);

  insertionAtTail(tail, 12);
  print(head);

  insertionAtTail(tail, 15);
  print(head);
}