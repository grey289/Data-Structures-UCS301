#include <iostream>
using namespace std;

int missing(int *array,int s){
    if (array[0]!=1){
        return array[0];
    }
    int i=1;
    for (i=1;i<s;++i){
    if (array[i]!=i+1) {

        return i+1;}
    }
    return -1;
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
    int s=sizeof(arr)/sizeof(arr[0]);
    //sorting array 
    int num=missing(arr,s);
    cout <<"for the array ;-"<<endl;
    for (i=0;i<elements;i++){
        cout<<arr[i]<<"\t";
    }
    if (num==-1){
        cout<<endl<<"there is no missing number in array"<<endl;
        
    } else cout<<endl<<"the missing number is "<<num<<endl;

    return 0; 
}