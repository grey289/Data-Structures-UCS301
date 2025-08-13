#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void deleter(int *array,int index,int size){
    int h;
    for(h=index;h<size;h++){
        array[h]=array[h+1];
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

    for (i=0;i<elements;i++){
        for(j=i+1;j<elements;j++){
            if (arr[i]==arr[j]){
            deleter(arr,j,elements);
            j--;
            elements--;
            }
        }
    }

    cout<<"the updated array is :-"<<endl;
    for(i=0;i<elements;i++){
        cout<<arr[i]<<" ";
    }
    return 0; 
}