/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  // Function to get length of the list
  int getLength(ListNode *head)
  {
    ListNode *temp = head;
    int count = 0;

    while (temp != NULL)
    {
      count++;
      temp = temp->next;
    }
    return count;
  }

public:
  ListNode *middleNode(ListNode *head)
  {
    int len = getLength(head);
    ListNode *temp = head;
    int cnt = 0;

    while (cnt < len / 2)
    {
      temp = temp->next;
      cnt++;
    }

    return temp;
  }
};