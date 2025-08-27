#include <iostream>
using namespace std;

int main()
{
    cout<<"enter the order of which you want a matrix"<<endl;
    int r;
    cin>>r;int lenght=(r*(r-1))/2;
    int arr[lenght];
    for(int i=0;i<lenght;i++){
        if (i<r-1){
        cout<<"enter element of index ( "<<i+1<<","<<i<<")"<<endl;
        cin>>arr[i];
        } //else if 
    }
    return 0; 
}