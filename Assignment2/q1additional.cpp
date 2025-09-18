#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countPairsWithDiffK(vector<int>& arr, int k) {
    set<int> s;
    int count = 0;

    for (int x : arr) {
        // Check if (x - k) already exists
        if (s.find(x - k) != s.end())
            count++;

        // Check if (x + k) already exists
        if (s.find(x + k) != s.end())
            count++;

        // Insert current element
        s.insert(x);
    }
    return count;
}

int main() {
    vector<int> arr = {1, 5, 3, 4, 2};
    int k = 2;

    cout << "Count of pairs with difference " << k 
         << " = " << countPairsWithDiffK(arr, k) << endl;

    return 0;
}
