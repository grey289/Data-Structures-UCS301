#include <iostream>
using namespace std;
int finder(int *array,int size){;
        int sumt=((size+1)*size)/2,suma=0;
        for(int i=0;i<size;i++){
            suma=suma+array[i];
        }
        return sumt-suma;
}
int main()
{
   int elements,i=0,j,temp;
    cout<<"enter the number of elements you want to input: ";
    cin>>elements;
    cout<<"CAUTION ! ONLY ENTER NUMBERS FROM 0 TO "<<elements<<endl;
    int arr[100];
    for (i=0;i<elements;i++){
        cout<<"enter the "<<i+1<<" element"<<endl;
    cin>> arr[i];
    }

    int missing=finder(arr,elements);
    cout<<"the missing element is "<<missing<<endl;
    return 0; 
}