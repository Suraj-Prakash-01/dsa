
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

/* ---------- Approach 1 ----------*/

/*void reverse(Node *head, Node *curr, Node *prev)
{
  // Base Condition
  if (curr == NULL)
  {
    head = prev;
    return;
  }

  Node *forward = curr->next;
  reverse(head, forward, curr);
  curr->next = prev;
}
*/

/* ---------- Apporach 2 ---------- */

/*Node *reverse(Node *head)
{
  // Base Case
  if (head == NULL || head->next == NULL)
    return head;

  Node *newHead = reverse(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = NULL;
  return newHead;
}
*/

/* ---------- Approach 3 ---------- */

Node *reverse(Node *head)
{
  // Base Case
  if (head == NULL || head->next == NULL)
    return head;

  Node *chotaHead = reverse(head->next);
  head->next->next = head;
  head->next = NULL;
  return chotaHead;
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
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);

  // Print the original linked list
  cout << "Original Linked List: ";
  printLinkedList(head);

  // Reverse the linked list for approach 1
  // Node *curr = head;
  // Node *prev = NULL;
  // reverse(head, curr, prev);
  // return head;

  head = reverse(head);

  // Print the reversed linked list
  cout << "Reversed Linked List: ";
  printLinkedList(head);

  return 0;
}
