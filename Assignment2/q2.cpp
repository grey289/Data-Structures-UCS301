#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int arr[]={64,34,25,12,22,11,90},i=0,j,temp;
    int size=sizeof(arr)/sizeof(arr[0]);
    for (i=0;i<size;i++){
        for (j=0;j<size-i-1;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for (i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }


    return 0; 
}