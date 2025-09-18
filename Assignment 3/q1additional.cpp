#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool empty() { if (top==-1)return true; return false;}
    void push(int x) { if(top < MAX-1) arr[++top] = x; }
    void pop() { if(!empty()) top--; }
    int peek() { return arr[top]; }
};

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans[n];
    Stack s;

    for(int i=0; i<n; i++) {
        while(!s.empty() && s.peek() >= arr[i])
            s.pop();

        if(s.empty()) ans[i] = -1;
        else ans[i] = s.peek();

        s.push(arr[i]);
    }

    for(int i=0; i<n; i++)
        cout << ans[i] << " ";
}

/*
#include <iostream>
using namespace std;


int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans[n];
    Stack<int> s;

    for(int i=n-1; i>=0; i--) {
        while(!s.empty() && s.peek() =< arr[i])
            s.pop();

        if(s.empty()) ans[i] = 0;
        else ans[i] = arr.find(s.peek())-i;

        s.push(arr[i]);
    }

    return ans;
}

*/