#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st; // stores values 

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= arr[i])
                st.pop();

            if (!st.empty())
                ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }
};
int main(){

    return 0;
}