#include <iostream>
#include <stack>
#include <string>
using namespace std;

class sta{
stack<int> st;
int mini=10^6;
int val;
public:
void push(int ele){
    if(st.empty()){
        st.push(ele);
        mini=ele;
    } else {
        if(st.top()>mini){
            st.push(ele);
        }else {
            val=2*ele-mini;
            st.push(val);
            mini=ele;
        }
    }
}
void pop(){
    if(st.top()<mini){
        mini=2*mini-st.top();
    }
    st.pop();
}


void getmin(){
    cout<<mini<<endl;
}
};
int main()
{
    sta s;

    s.push(5);
    s.push(4);

    s.getmin();
    s.pop();
    s.getmin();
    return 0; 
}
/* TC=O(1) & SC=(2N)
class sta{
stack<pair<int,int>> st;
public:
void push(int ele){
    if(st.empty()){
        st.push({ele,ele});
    } else {
        if(st.top().first<ele){
            st.push({ele,st.top().first});
        }else {
            st.push({ele,ele});
        }
    }
}
void pop(){
    st.pop();
}
void top(){
    cout<<st.top().first<<endl;
}
void getmin(){
    cout<<st.top().second<<endl;
}
};
int main()
{
    sta s;

    s.push(5);
    s.push(4);

    s.getmin();
    s.pop();
    s.getmin();
    return 0; 
}
    */