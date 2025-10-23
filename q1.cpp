#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int target = 7;
    int n = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            cout << "Element found at index " << mid << endl;
            return 0; // exit program after finding the element
        } 
        else if (arr[mid] < target) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    cout << "Element not found" << endl;
    return 0;
}
