#include<iostream>

using namespace std;

int BinarySearchDescending(int arr[], int n, int key) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + ((end - start) >> 1);
        if (arr[mid] == key) return mid;
        else if (arr[mid] > key) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}


int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int key; cin >> key;
    
    int index = BinarySearchDescending(arr, n, key);
    cout << index << endl;
    return 0;    
}