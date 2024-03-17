// Floyd's Loop Detection Algorithm
bool floydDetectionLoop(Node *head)
{

  // Edge Case
  if (head == NULL)
    return false;

  Node *fast = head;
  Node *slow = head;

  while (slow != NULL || fast != NULL)
  {
    // 1st step
    fast = fast->next;

    if (fast != NULL)
      // 2nd Step
      fast == fast->next;

    // 1st step
    slow = slow->next;

    // They will eventually meet if they are in a loop
    if (slow == fast)
      return 1;
  }
  return 0;
}

// Function to find the meeting point
Node *getStartingNode(Node *head)
{
  // Edge Case
  if (head == NULL)
    return NULL;

  Node *intersection = floydDetectionLoop(head);
  Node *start = head;

  while (intersection != start)
  {
    intersection = intersection->next;
    start = start->next;
  }

  return start;
}

// Optional Code for removing the node
void removeLoop(Node *head)
{

  // Edge Case
  if (head == NULL)
    return;

  Node *startOfLoop = getStartingNode(head);
  Node *temp = startOfLoop;

  while (temp->next != startOfLoop)
    temp = temp->next;

  temp->next = NULL;
}