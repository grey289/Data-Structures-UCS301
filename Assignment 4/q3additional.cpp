#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue <int> q;
    queue<int> ans;
    stack<int> st;
    int ele1,ele2;
    q.push(30);
    q.push(10);
    q.push(20);
    q.push(40);
  
    st.push(q.front());
    q.pop();
    int n=q.size();
    for (int i=0;i<n;i++){
        ele2=q.front();
        if(st.top()>ele2){ans.push(ele2);
            q.pop();}
        else {ans.push(st.top());st.pop();st.push(ele2);
            q.pop();}

    }
    while(!st.empty()){
    ans.push(st.top());st.pop();}
    for(int i=0;i<n+1;i++){
        cout<<ans.front()<<"\t";
        ans.pop();
    }
    
    return 0; 
}