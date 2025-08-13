#include <iostream>
using namespace std;

int main()
{
    int r1,c1,i=0,j=0;
    cout<<"enter the number of rows you want for matrix 1"<<endl;
    cin>>r1;
    cout<<"enter the number of columns you want for matrix 1"<<endl;
    cin>>c1;


    int m1[r1][c1];
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            cout<<"enter element of ("<<i+1<<","<<j+1<<") of matrix 1"<<endl;
            cin>>m1[i][j];
        }
    }

     for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            cout<<m1[i][j]<<"\t";
        }
        cout<<endl;
    }
cout<<endl<<endl;
    int r2,c2;
    cout<<"enter the number of rows you want for matrix 2"<<endl;
    cin>>r2;
    cout<<"enter the number of columns you want for matrix 2"<<endl;
    cin>>c2;


    int m2[r2][c2];
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            cout<<"enter element of ("<<i+1<<","<<j+1<<") of matrix 2"<<endl;
            cin>>m2[i][j];
        }
    }

     for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            cout<<m2[i][j]<<"\t";
        }
        cout<<endl;
    }

    int ans;
    if(c1==r2){
        cout<<"matrix multiplication is possible"<<endl;
        cout<<"do you want multiplied matrix output ?(yes=1  no=0)"<<endl;
        cin>>ans;
    }else{
        cout<<"matrix multiplication is NOT possible"<<endl; 
    }
    int k=0;
    if (ans==1){
        int m3[r1][c2];
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                m3[i][j]=0;
                for(k=0;k<c1;k++){
                    m3[i][j]=m3[i][j]+ m1[i][k]*m2[k][j];
                }
            }
        }

        for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            cout<<m3[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    }
    ans=0;
    int matrix=0;
    cout<<"Do you want transpose of matrix ? (yes=1 no=0)"<<endl;
    cin>>ans;
    if(ans==1){
        cout<<"which matrix do you want transpose of ? (1/2)"<<endl;
        cin>>matrix;
        if(matrix==1){
            int m4[c1][r1];
            for(i=0;i<r1;i++){
                for(j=0;j<c1;j++){
                    m4[j][i]=m1[i][j];
                }
            }

            for(i=0;i<c1;i++){
                for(j=0;j<r1;j++){
                    cout<<m4[i][j]<<"\t";
        }
        cout<<endl;
        }
    } if(matrix==2){
            int m5[c2][r2];
            for(i=0;i<r2;i++){
                for(j=0;j<c2;j++){
                    m5[j][i]=m2[i][j];
                }
            }

            for(i=0;i<c2;i++){
                for(j=0;j<r2;j++){
                    cout<<m5[i][j]<<"\t";
        }
        cout<<endl;
        }
    }
     
    }
    return 0; 
}