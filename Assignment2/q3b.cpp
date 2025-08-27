#include <iostream>
using namespace std;
int finder(int *array, int size){
    int s=0,l=size-1,m;
   
    while (s<=l){
         m=(s+l)/2;
    if (array[m]==m+1){s=m+1;} 
    else {l=m-1;}
        }
  
      return s+1;
}
int main()
{
   int elements,i=0,j,temp;
    cout<<"enter the number of elements you want to input: ";
    cin>>elements;
    cout<<"CAUTION ! ONLY ENTER NUMBERS FROM 1 TO "<<elements+1<<endl;
    int arr[100];
    for (i=0;i<elements;i++){
        cout<<"enter the "<<i+1<<" element"<<endl;
    cin>> arr[i];
    }

    int missing=finder(arr,elements);
    cout<<"the missing element is "<<missing<<endl;
    return 0; 
}