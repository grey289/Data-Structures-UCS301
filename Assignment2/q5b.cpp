#include <iostream>
using namespace std;

int main()
{
    cout<<"enter the order of which you want a matrix"<<endl;
    int r;
    cin>>r;
    int arr[3*r-2];
    for(int i=0;i<3*r-2;i++){
        if (i<r-1){
        cout<<"enter the element ("<<i+1<<" , "<<i<<")"<<endl;
        cin>>arr[i];}
        else if (i<2*r-1){
            cout<<"enter the element ("<<i-r+1<<" , "<<i-r+1<<")"<<endl;
            cin>>arr[i];
        }
        else{
            cout<<"enter the element ("<<i-2*r+2<<" , "<<i-2*r+3<<")"<<endl;
            cin>>arr[i];
        }
    }
    cout<<"entered matrix elements are :-"<<endl;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= r; j++) {
            if(i - j == 1)           // lower diagonal
                cout << arr[i-2] << "\t";
            else if(i - j == 0)      // main diagonal
                cout << arr[(r-1) + (i-1)] << "\t";
            else if(i - j == -1)     // upper diagonal
                cout << arr[(2*r-1) + (i-1)] << "\t";
            else
                cout << "0\t";       // outside tri-diagonal → zero
        }
        cout << endl;
    }
    return 0; 
}