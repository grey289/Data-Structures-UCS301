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
     bool isempty(){
        if(top==-1){
            return true;
        } return false;
     }
    void pop(){
        if (top==-1){
            cout<<"stack is empty. Stack underflow"<<endl;
            return;
        }else top=top-1;}

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
    cout<<"enter a expression :"<<endl;
    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[' )
        {s.push(str[i]);}
        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            if(s.isempty()){cout<<"parenthesis are NOT balenced "<<endl;
                exit(0);
                break;}
            s.pop();
        }
    }
    if(s.isempty()){
        cout<<"parenthesis are balenced "<<endl;
    } else cout<<"parenthesis are NOT balenced "<<endl;
    return 0; 
}