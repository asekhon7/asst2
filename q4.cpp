#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2, s;
    cout << "Enter first string: ";
    getline(cin, s1);
    cout << "Enter second string: ";
    getline(cin, s2);
    cout << "Concatenated: " << s1 + s2 << endl;

    cout << "Enter a string to reverse: ";
    getline(cin, s);
    string rev = "";
    for (int i = s.length() - 1; i >= 0; i--)
        rev += s[i];
    cout << "Reversed: " << rev << endl;

    cout << "Enter a string to remove vowels: ";
    getline(cin, s);
    string noVowel = "";
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        char l = (c >= 'A' && c <= 'Z') ? c + 32 : c;
        if (l!='a' && l!='e' && l!='i' && l!='o' && l!='u')
            noVowel += c;
    }
    cout << "Without vowels: " << noVowel << endl;

    int n;
    cout << "Enter number of strings to sort: ";
    cin >> n;
    cin.ignore();
    string arr[n];
    for (int i = 0; i < n; i++)
        getline(cin, arr[i]);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Sorted strings:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    char ch;
    cout << "Enter a character to convert case: ";
    cin >> ch;
    if (ch >= 'A' && ch <= 'Z')
        cout << "Lowercase: " << char(ch + 32) << endl;
    else if (ch >= 'a' && ch <= 'z')
        cout << "Uppercase: " << char(ch - 32) << endl;
    else
        cout << "Not an alphabetic character." << endl;

    return 0;
}