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

class Compare
{
public:
  bool operator()(ListNode *a, ListNode *b)
  {
    return a->val > b->val;
  }
};

class Solution
{
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    // Create a priority queue to store the nodes of the linked lists
    priority_queue<ListNode *, vector<ListNode *>, Compare> minHeap;
    int k = lists.size();

    // Handle edge case where there are no linked lists
    if (k == 0)
    {
      return NULL;
    }

    // Step 1: Push the head of each list into the priority queue
    for (int i = 0; i < k; i++)
    {
      if (lists[i] != NULL)
      {
        minHeap.push(lists[i]);
      }
    }

    ListNode *head = NULL;
    ListNode *tail = NULL;

    // Merge the linked lists
    while (!minHeap.empty())
    {
      ListNode *top = minHeap.top();
      minHeap.pop();

      // Push the next node of the current list into the priority queue
      if (top->next != NULL)
      {
        minHeap.push(top->next);
      }

      // Initialize the head of the merged list
      if (head == NULL)
      {
        head = top;
        tail = top;
      }
      else
      {
        // Append to the end of the merged list
        tail->next = top;
        tail = top;
      }
    }

    return head;
  }
};