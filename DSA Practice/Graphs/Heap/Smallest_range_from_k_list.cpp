class node
{
public:
  int data;
  int row;
  int col;

  node(int d, int r, int c)
  {
    data = d;
    row = r;
    col = c;
  }
};

class compare
{
public:
  bool operator()(node *a, node *b)
  {
    return a->data > b->data;
  }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
  int mini = INT_MAX;
  int maxi = INT_MIN;
  priority_queue<node *, vector<node *>, compare> minHeap;

  for (int i = 0; i < k; i++)
  {
    int element = a[i][0];
    mini = min(mini, element);
    maxi = max(maxi, element);
    minHeap.push(element);
  }
}