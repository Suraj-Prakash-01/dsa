
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
class Node
{
public:
  // Data stored in the node
  int data;

  // Pointer to the next node in the list
  Node *next;

  // Constructor with both data and
  // next node as parameters
  Node(int data1, Node *next1)
  {
    data = data1;
    next = next1;
  }

  // Constructor with only data as a
  // parameter, sets next to nullptr
  Node(int data1)
  {
    data = data1;
    next = nullptr;
  }
};

Node *reverse(Node *head)
{
  Node *forward = NULL;
  Node *prev = NULL;
  Node *curr = head;

  // It's like swapping position and updating at the same time
  while (curr != NULL)
  {
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
  }
  return prev;
}

// Function to print the linked list
void printLinkedList(Node *head)
{
  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  // Create a linked list with
  // values 1, 3, 2, and 4
  Node *head = new Node(1);
  head->next = new Node(3);
  head->next->next = new Node(2);
  head->next->next->next = new Node(4);

  // Print the original linked list
  cout << "Original Linked List: ";
  printLinkedList(head);

  // Reverse the linked list
  head = reverse(head);

  // Print the reversed linked list
  cout << "Reversed Linked List: ";
  printLinkedList(head);

  return 0;
}
