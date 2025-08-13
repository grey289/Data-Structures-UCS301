#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void reverser(int *array,int size){
    int i=0,j=size-1,tmp;
    while(i!=j && i<j){
        tmp=array[i];
        array[i]=array[j];
        array[j]=tmp;
        i++;
        j--;
    }
}
int main()
{
    int elements,i=0,j,k;
    cout<<"enter the number of elements you want to input: ";
    cin>>elements;
    int arr[100];
    for (i=0;i<elements;i++){
        cout<<"enter the "<<i+1<<" element"<<endl;
        cin>>arr[i];
    }
    reverser(arr,elements);
    cout<<"the updated array is :-"<<endl;
    for(i=0;i<elements;i++){
        cout<<arr[i]<<"\t";
    }
    return 0; 
}