#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n; i++) {
        bool isDistinct = true;
        for(int j=0; j<i; j++) {
            if(arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }
        if(isDistinct)
            count++;
    }

    cout << "Total number of distinct elements: " << count << endl;
    return 0;
}