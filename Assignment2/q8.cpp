#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<int> distinct; // stores only unique values
    for (int i = 0; i < n; i++) {
        distinct.insert(arr[i]);
    }

    cout << "Total number of distinct elements = " << distinct.size() << endl;
    return 0;
}