#include <iostream>
#include <stack>
#include <string>
using namespace std;

int postfixeval(string s) {
    stack<int> st;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            st.push(c - '0');  // convert char digit to int
        } else {
            int t1 = st.top(); st.pop();
            int t2 = st.top(); st.pop();
            int ans;
            if (c == '+') ans = t2 + t1;
            else if (c == '-') ans = t2 - t1;
            else if (c == '*') ans = t2 * t1;
            else if (c == '/') ans = t2 / t1;
            else ans=t2^t1;
            st.push(ans);
        }
    }
    return st.top();
}

int main() {
    string c = "23*54*+";
    int result = postfixeval(c);
    cout << result;
    return 0;
}
