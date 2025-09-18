#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> st; // stores indices of days

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();

            if (!st.empty())
                ans[i] = st.top() - i;

            st.push(i);
        }
        return ans;
    }
};
int main(){

    return 0;
}