#include <iostream>
#include <string>
using namespace std;
class stack{
   
    char element[100];
    int top=-1;
    public:
     void push(char c){
        if(top==100-1){
            cout<<"stack overflow"<<endl;
            return;
        }
        top=top+1;
        element[top]=c;

     }
   
    void display(){
        if (top==-1){
            cout<<"stack is empty "<<endl;
            return;
        } 
        for (int i=top;i>=0;i--){
            cout<<element[i];
        } cout<<endl;
    }

};
int main()
{
    stack s;
    string str;
    cout<<"enter a word :"<<endl;
    cin>>str;
    
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }
    
        s.display();
    
    return 0; 
}