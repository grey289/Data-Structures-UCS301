#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int r1,c1,i=0,j=0;
    cout<<"enter the number of rows you want for matrix "<<endl;
    cin>>r1;
    cout<<"enter the number of columns you want for matrix "<<endl;
    cin>>c1;


    int m1[r1][c1];
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            cout<<"enter element of ("<<i+1<<","<<j+1<<") of matrix "<<endl;
            cin>>m1[i][j];
        }
    }

     for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            cout<<m1[i][j]<<"\t";
        }
        cout<<endl;
    }

    int rowsum;
    for (i=0;i<r1;i++){
        rowsum=0;
        for (j=0;j<c1;j++){
            rowsum=rowsum+m1[i][j];
        }
        cout<<"the sum of all the elements of row "<<i+1<<" is "<<rowsum<<endl;
    }
    for (i=0;i<c1;i++){
        rowsum=0;
        for (j=0;j<r1;j++){
            rowsum=rowsum+m1[j][i];
        }
        cout<<"the sum of all the elements of column "<<i+1<<" is "<<rowsum<<endl;
    }
    return 0; 
}