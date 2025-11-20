#include <bits/stdc++.h>
using namespace std;

// Improved Selection Sort – Picks min and max in each pass
void improvedSelectionSort(vector<int> &a) {
    int left = 0;
    int right = a.size() - 1;

    while(left < right) {
        int minIndex = left;
        int maxIndex = right;

        // Ensure correct ordering of indices initially
        if(a[minIndex] > a[maxIndex]) swap(a[minIndex], a[maxIndex]);

        for(int i = left+1; i < right; i++) {
            if(a[i] < a[minIndex]) minIndex = i;
            if(a[i] > a[maxIndex]) maxIndex = i;
        }

        swap(a[left], a[minIndex]);

        // If max element was at left, adjust its index
        if(maxIndex == left) maxIndex = minIndex;

        swap(a[right], a[maxIndex]);

        left++;
        right--;
    }
}

int main() {
    vector<int> a = {20, 5, 7, 1, 48, 30, 2};

    cout << "Original Array: ";
    for(int x : a) cout << x << " ";
    cout << "\n";

    improvedSelectionSort(a);

    cout << "Improved Selection Sort Result: ";
    for(int x : a) cout << x << " ";
    cout << "\n";

    return 0;
}
