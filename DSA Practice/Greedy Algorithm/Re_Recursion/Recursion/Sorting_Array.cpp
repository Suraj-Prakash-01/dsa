#include <iostream>
using namespace std;

// Function to perform Bubble Sort recursively
void bubbleSortRecursive(int arr[], int n) {
    if (n == 1) {
        // If there is only one element left, then the array is already sorted
        return;
    }

    bool flag = false;

    // Last i elements are already sorted, so we don't need to check them again
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
            flag = true;
        }
    }

    // If no two adjacent elements were swapped during above iteration, then the array is already sorted
    if (!flag) {
        return;
    }

    // Call the same function recursively for the smaller subarray
    bubbleSortRecursive(arr, n - 1);
}

// Helper function to swap two integers
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// Driver Code
int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSortRecursive(arr, n);

    cout << "Sorted Array in Ascending Order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}