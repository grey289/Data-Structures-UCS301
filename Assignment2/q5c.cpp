#include <iostream>
using namespace std;

int main()
{
    cout<<"enter the order of which you want a matrix"<<endl;
    int r;
    cin>>r;
    int lenght=(r*(r-1))/2;
    int arr[lenght];
    int index = 0;
for (int i = 0; i < r; i++) {
    for (int j = 0; j < i; j++) {  
        cout<<"enter the ("<<i<<","<<j<<")"<<endl;
        cin >> arr[index];
        index++;
    }
}
index =0;

cout<<"the entered matrix is :-"<<endl;
for(int i=0;i<r;i++){
    for(int j=0;j<r;j++){
        if(j<i){
            cout<<arr[index]<<"\t";
            index++;
        } else cout<<"0\t";
    }
    cout<<endl;
}
    return 0; 
}