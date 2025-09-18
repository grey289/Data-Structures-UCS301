#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int n;
    cout<<"enter the no of elements you want to enter "<<endl;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"enter the "<<i+1<<" element"<<endl;
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    int inv=0;
    for (int i = 0; i < n; i++)
    {
        for(int j=i;j<n;j++){
            if(arr[i]>arr[j]){
                inv++;
            }
        }
    }
    cout<<"the number of inversions in the arrays are "<<inv;
    
    
    return 0; 
}