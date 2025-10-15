#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number "<<endl;
    cin>>n;
    queue <int> q;
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i+1<<" element"<<endl;
        int temp;
        cin>>temp;
        q.push(temp);
    }
    for (int i=0;i<n;i++){
        int ele1=q.front();
        q.pop();
        for(int j=0;j<n-1;j++){
            int ele2=q.front();

            if(ele1<ele2){q.push(ele1);ele1=ele2;}
            else{ q.push(ele2);}
            q.pop();
        }
        q.push(ele1);
    }
    for(int k=0;k<n;k++){
        cout<<q.front()<<"\t";
        q.pop();
    }
    return 0;
}