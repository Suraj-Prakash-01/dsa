/* Heap is a Complete Binary Tree which comes with a heap order property
  For figuring out heap question, check for 'k' and 'smallest/largest'
*/

#include <iostream>
#include <queue>
using std::cin;
using std::cout;
using std::endl;

class heap
{
public:
  int arr[100];
  int size = 0;

  heap()
  {
    arr[0] = -1;
    size = 0;
  }

  void insert(int val)
  {
    size = size + 1;
    int index = size;
    arr[index] = val;

    while (index > 1)
    {
      int parent = index / 2;

      if (arr[parent] < arr[index])
      {
        std::swap(arr[parent], arr[index]);
        index = parent;
      }
      else
        return;
    }
  }

  void print()
  {
    for (int i = 0; i <= size; i++)
      cout << arr[i] << " ";
    cout << endl;
  }

  void deleteFromHeap()
  {
    if (size == 0)
    {
      cout << "Nothing to delete" << endl;
      return;
    }

    // Step 1: Put last element into first index
    arr[1] = arr[size];

    // Step 2: Remove last element
    size--;

    // Step 3: Take root node to it's correct position
    int i = 1;
    while (i < size)
    {
      int leftIndex = 2 * i;
      int rightIndex = 2 * i + 1;

      if (leftIndex <= size && arr[i] < arr[leftIndex])
      {
        std::swap(arr[i], arr[leftIndex]);
        i = leftIndex;
      }

      else if (rightIndex <= size && arr[i] < arr[rightIndex])
      {
        std::swap(arr[i], arr[rightIndex]);
        i = rightIndex;
      }
      else
        return;
    }
  }
};

void heapify(int arr[], int n, int i)
{

  int largest = i;
  int left = 2 * i;
  int right = (2 * i) + 1;

  if (left <= n && arr[largest] < arr[left])
    largest = left;
  if (right <= n && arr[largest] < arr[right])
    largest = right;

  if (largest != i)
  {
    std::swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n)
{

  int size = n;

  while (size > 1)
  {
    // Step 1: swap
    std::swap(arr[size], arr[1]);
    size--;

    // Step 2: heapify
    heapify(arr, size, 1);
  }
}

int main()
{
  heap h;
  h.insert(50);
  h.insert(55);
  h.insert(53);
  h.insert(52);
  h.insert(54);
  h.print();

  h.deleteFromHeap();
  h.print();

  int arr[6] = {-1, 54, 53, 55, 52, 50};
  int n = 5;

  // Heap Creation
  for (int i = n / 2; i >= 1; i--)
    heapify(arr, n, i);

  cout << "Printing the array now: " << endl;
  for (int i = 1; i <= n; i++)
    cout << arr[i] << " ";
  cout << endl;

  // Heap Sort
  heapSort(arr, n);

  cout << "Printing the Sorted Array: " << endl;
  for (int i = 1; i <= n; i++)
    cout << arr[i] << " ";
  cout << endl;

  cout << "Using Priority Queue here " << endl;

  // Max Heap
  std::priority_queue<int> pq;

  pq.push(4);
  pq.push(2);
  pq.push(5);
  pq.push(3);

  cout << "Element at Top " << pq.top() << endl;
  pq.pop();
  cout << "Element at Top " << pq.top() << endl;
  cout << "Size is: " << pq.size() << endl;
  if (pq.empty())
    cout << "pq is Empty" << endl;
  else
    cout << "pq is not Empty" << endl;

  // min Heap
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

  minHeap.push(4);
  minHeap.push(2);
  minHeap.push(5);
  minHeap.push(3);

  cout << "Element at Top " << minHeap.top() << endl;
  minHeap.pop();
  cout << "Element at Top " << minHeap.top() << endl;
  cout << "Size is: " << minHeap.size() << endl;
  if (minHeap.empty())
    cout << "pq is Empty" << endl;
  else
    cout << "pq is not Empty" << endl;
}