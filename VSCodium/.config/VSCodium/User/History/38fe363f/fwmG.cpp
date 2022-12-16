#include<iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> arr, int n, int key) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + ((end - start) >> 1);
        if (arr[mid] == key) return mid;
        else if (arr[mid] > key) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int main() {
    int n; cin >> n; 
    vector<int> arr(n);
    // for (int i = 0; i < n; i++) cin >> arr[i];
    for
    int key; cin >> key;

    int ascending = BinarySearch(arr, n, key);
    cout << ascending << "\n";

 }