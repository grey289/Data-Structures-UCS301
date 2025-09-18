#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int a[]={3,1,2,4};
    int b[4];
    stack <int> s;
    int j=0;
    for(int i =0;i<4;i++){
        if(s.empty()){
            s.push(a[i]);
        }
        else if(s.top()>a[i]){
            b[j]=a[i];
            j++;
        }
        else{
            b[j]=s.top();
            s.pop();
            s.push(a[i]);
        }
    }

    for(int i =0;i<4;i++){
        cout<<b[i]<<endl;
    }
    return 0; 
}