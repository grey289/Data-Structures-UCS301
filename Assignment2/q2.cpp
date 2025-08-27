#include <iostream>
using namespace std;
void bubblesort(int arr[],int size){
    int i=0,j,temp;
    for(;i<size;i++){
        bool swap=false;
        for(j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=true;
            }
        }
        if(swap==false) return;
    }
    return;
}
int main()
{
    int arr[]={64,34,25,12,22,11,90},i=0;
    int size=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,size);
    for (;i<size;i++){
        cout<<arr[i]<<"\t";
    }
    return 0; 
}