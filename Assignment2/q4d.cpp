#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    
    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore(); // Clear the newline character from input buffer
    
    vector<string> strings(n);
    
    cout << "Enter " << n << " strings:" << endl;
    for (int i = 0; i < n; i++) {
        getline(cin, strings[i]);
    }
    
    // Sort strings in alphabetical order
    sort(strings.begin(), strings.end());
    
    cout << "\nStrings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << strings[i] << endl;
    }
    
    return 0;
}