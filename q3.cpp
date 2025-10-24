#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        if(arr[i+1] - arr[i] != 1)
            return arr[i] + 1;
    }
    return n; 
}

int findMissingBinary(int arr[], int n) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == mid + 1)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left + 1;
}

int main() {
    int n;
    cout << "Enter n (array should have n-1 elements): ";
    cin >> n;
    int arr[n-1];
    cout << "Enter " << n-1 << " sorted elements from 1 to " << n << ": ";
    for(int i=0; i<n-1; i++)
        cin >> arr[i];

    cout << "Missing number (Linear Search): " << findMissingLinear(arr, n) << endl;
    cout << "Missing number (Binary Search): " << findMissingBinary(arr, n) << endl;

    return 0;
}