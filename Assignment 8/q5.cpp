#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class heaps{
public:
int arr[100];
int size=0;
void insert(int val){
    size++;
    int ind=size;

    arr[ind]=val;
    while(ind>1){
        int parent=ind/2;
        if(arr[parent]<arr[ind]) {swap(arr[parent],arr[ind]);
        ind=parent;
        }else{
            return;
        }
    }
}

void print(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<"\t";
    } cout<<endl;
}
void deleter(){
    if(size==0){cout<<"underflow"; return;}
    arr[1]=arr[size];
    size--;
    int par=1;
    while(par<=size){
        int left=par*2;
        int right=par*2+1;

        if(left< size && arr[par]<arr[left]){
            swap(arr[par],arr[left]);
            par=left;
        }
        if(right< size && arr[par] < arr[right]){
            swap(arr[par],arr[right]);
            par = right;

        }
    }
}


};
void heapify(int arr[], int size, int i){
    int largest= i;
    int left=2*i;
    int right=2*i+1;
    if(left<size && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<size && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,i,largest);
    }
}

int main()
{
    heaps o1;
    o1.insert(5);
    o1.insert(7);
    o1.insert(1);
    o1.insert(12);
    o1.print();
    return 0; 
}