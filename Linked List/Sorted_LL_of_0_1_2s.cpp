/* ---------- Approach 1 ----------*/

Node *sortList(Node *head)
{
  // Write your code here.
  int zeroCount = 0, oneCount = 0, twoCount = 0;

  Node *temp = head;
  while (temp != NULL)
  {
    if (temp->data == 0)
      zeroCount++;
    else if (temp->data == 1)
      oneCount++;
    else if (temp->data == 2)
      twoCount++;
    temp = temp->next;
  }

  temp = head;
  while (temp != NULL)
  {
    if (zeroCount != 0)
    {
      temp->data = 0;
      zeroCount--;
    }
    else if (oneCount != 0)
    {
      temp->data = 1;
      oneCount--;
    }
    else if (twoCount != 0)
    {
      temp->data = 2;
      twoCount--;
    }
    temp = temp->next;
  }
  return head;
}