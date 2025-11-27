#include <bits/stdc++.h>
using namespace std;
vector<int> sortEvenOdd(vector<int>& arr) {
    vector<int> even, odd;

    for (int i = 0; i < arr.size(); i++) {
        (i % 2 == 0 ? even : odd).push_back(arr[i]);
    }

    sort(even.begin(), even.end());                // increasing
    sort(odd.begin(), odd.end(), greater<int>()); // decreasing

    vector<int> res;
    res.insert(res.end(), even.begin(), even.end());
    res.insert(res.end(), odd.begin(), odd.end());
    return res;
}
