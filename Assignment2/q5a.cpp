#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    cout<<"enter the order of which you want a matrix"<<endl;
    int r;
    cin>>r;
    int arr[r],m[r][r];
    cout<<"enter the diagonal elements of the array "<<endl;
    for(int i=0;i<r;i++){
        cout<<"enter the "<<i+1<<" element"<<endl;
        cin>>arr[i];
    }
    cout<<"the matrix is "<<endl;
    for(int i=0;i<r;i++){
        for (int j=0;j<r;j++){
            // cout<<"enter the element of matrix ("<<i+1<<" , "<<j+1<<")"<<endl;
            // cin>>m[i][j];
            if(i==j) cout<<arr[i]<<"\t";
            else cout<<"0\t";
        }
        cout<<endl;
    }
    return 0; 
}