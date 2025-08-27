#include <iostream>
using namespace std;
int binarysearch(int *array,int element,int size){
    int l=0,h=size-1;
    while (l<=h){
    int m=(l+h)/2;
    if (array[m]==element) return m;

    if (array[m]>element) h=m-1;
            
    else l=m+1;
                
            }
        
    
    return -1;
}
int linearsearch(int *array,int element,int size){
    int i=0;
    for(;i<size;i++){
        if (array[i]==element) return i;
    }
    return -1;
} 
int main()
{
    cout<<"enter the number of elements"<<endl;
    int terms,i=0;
    cin>>terms;
    int arr[terms];
    for(;i<terms;i++){
        cout<<"enter the "<<i+1<<" element"<<endl;
        cin>>arr[i];
    }
    cout<<"enter an element to search"<<endl;
    int element;
    cin>>element;
    int bin=binarysearch(arr,element,terms);
    int lin=linearsearch(arr,element,terms);
    cout<<"the index of the element is "<<bin<<" from binary search"<<endl;
    cout<<"the index of the element is "<<lin<<" from linear search"<<endl;
    return 0; 
}