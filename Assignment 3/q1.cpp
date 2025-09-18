#include <iostream>
using namespace std;
struct stack{
    int size;
    int *element;
    int top=-1;
    stack(){
        element=nullptr;
    }
    ~stack(){
        delete[] element;
    }
    bool isfull(){
        if (top==size-1) return true;
        return false;
    }
    bool isempty(){
        if(top==-1) return true;
        return false;
    }
    void sizer(){
        cout<<"enter the size of the stack: "<<endl;
        cin>>size;
        element=new int[size];
    }
    void push(int x){
        if(isfull()){
            cout<<"stack is full. Stack overflow"<<endl;
            return;
        } else {
            top=top+1;
            element[top]=x;
        }
    }
    void pop(){
        if (isempty()){
            cout<<"stack is empty. Stack underflow"<<endl;
            return;
        }else top=top-1;
    }
    void peek(){
        if(isempty()){
            cout<<"stack is empty. stack underflow"<<endl;
            return;
        } else cout<<"the top element = "<<element[top]<<endl;
    }
    void display(){
        if (isempty()){
            cout<<"stack is empty "<<endl;
            return;
        } 
        for (int i=top;i>=0;i--){
            cout<<element[i]<<"\t";
        } cout<<endl;
    }

};
int main()
{
    stack s;
    s.sizer();
    cout<<"possible operations are:- "<<endl<<
        "\n1 = push \n 2=pop \n 3=isempty \n 4=isfull \n5=display all elements\n 6=peek \n0=exit"<<endl;
        int ops;
        do{
            cout<<"what operations do you want "<<endl;
            cin>>ops;
            switch (ops)
            {
            case 1:
                cout<<"enter element to add in stack"<<endl;
                int ele;
                cin>>ele;
                s.push(ele);
                break;
            
            case 2:
                s.pop();
                break;
            case 3:
            s.isempty();
            break;
            case 4:
            s.isfull();
            break;
            case 5:
            s.display();
            break;
            case 6:
            s.peek();
            break;
            case 0:
            cout<<"exiting program "<<endl;
            break;
            default:
            cout<<"invalid operation please try again"<<endl;
            }

        }while(ops!=0);
    return 0; 
}