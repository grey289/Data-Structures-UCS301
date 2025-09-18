#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prio(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string infixtopostfix(string s) {
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        // Operand (letters or digits)
        if ((c >= 'A' && c <= 'Z') || 
            (c >= 'a' && c <= 'z') || 
            (c >= '0' && c <= '9')) {
            ans += c;
        }
        // Opening parenthesis
        else if (c == '(') {
            st.push(c);
        }
        // Closing parenthesis
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // pop '('
        }
        // Operator
        else {
            while (!st.empty() && prio(c) <= prio(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    // Pop all remaining operators
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main() {
    string test = "q+r-c*(a+b)";
    cout << infixtopostfix(test);
    return 0;
}
