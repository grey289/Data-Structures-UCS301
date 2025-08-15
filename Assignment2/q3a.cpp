#include <iostream>
using namespace std;

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
    //sorting array 
   
    for (i=0;i<elements;i++){
        for (j=0;j<elements-i-1;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for (i=0;i<elements;i++){
        cout<<arr[i]<<"\t";
    }

    //sorted array of index till n can have distict numbers from 1 to n 
    int missing =0,num;
    for (i=0;i<elements-1;i++){
        if (arr[i+1]==arr[i]+1)
        continue;
        else {num=arr[i]+1;
            missing =1;}
    }

    if (missing==1) cout<<"the missing element is "<<num<<endl;
    else cout<<"no missing numbers in array"<<endl;
    return 0; 
}