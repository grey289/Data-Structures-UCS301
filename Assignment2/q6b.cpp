#include <iostream>
using namespace std;

int main(){
    int r1, c1;
    cout << "Enter rows for matrix 1: ";
    cin >> r1;
    cout << "Enter cols for matrix 1: ";
    cin >> c1;

    int m1[r1][c1];
    int s1[100][3];
    int counter1 = 0;

    // Read matrix and build sparse form
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin >> m1[i][j];
            if(m1[i][j]!=0){
                counter1++;
                s1[counter1][0] = i;
                s1[counter1][1] = j;
                s1[counter1][2] = m1[i][j];
            }
        }
    }
    s1[0][0] = r1;
    s1[0][1] = c1;
    s1[0][2] = counter1;
    //printing matrix
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cout<< m1[i][j]<<"\t";}cout<<endl;}
    // Print sparse
    cout << "Sparse matrix form:\n";
    cout<<"row\tCol\tValue"<<endl;
    for(int i=0;i<=counter1;i++)
        cout << s1[i][0] << "\t" << s1[i][1] << "\t" << s1[i][2] << "\n";
    cout<<endl;
    int r2, c2;
    cout << "Enter rows for matrix 2: ";
    cin >> r2;
    cout << "Enter cols for matrix 2: ";
    cin >> c2;

    int m2[r2][c2];
    int s2[100][3];
    int counter2 = 0;

    // Read matrix and build sparse form
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin >> m2[i][j];
            if(m2[i][j]!=0){
                counter2++;
                s2[counter2][0] = i;
                s2[counter2][1] = j;
                s2[counter2][2] = m2[i][j];
            }
        }
    }
    s2[0][0] = r2;
    s2[0][1] = c2;
    s2[0][2] = counter2;
    //printing matrix
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cout<< m2[i][j]<<"\t";}cout<<endl;}
    // Print sparse
    cout << "Sparse matrix form:\n";
    cout<<"row\tCol\tValue"<<endl;
    for(int i=0;i<=counter2;i++)
        cout << s2[i][0] << "\t" << s2[i][1] << "\t" << s2[i][2] << "\n";
    cout<<endl;

    cout<<"do you want to perform matrix addition (yes=1 no=0) ?"<<endl;
    int ans;
    cin>>ans;
    
    int s3[100][3],i3=1;
    if(ans==1){
        if (s1[0][0]==s2[0][0] && s1[0][1]==s2[0][1]){
            s3[0][0]=s1[0][0];
            s3[0][1]=s2[0][1];
            //perform addition
            int i1=1,i2=1;
            while(i1<=counter1 && i2<=counter2){
                if(s1[i1][0]==s2[i2][0]){
                    if(s1[i1][1]==s2[i2][1]){
                        s3[i3][0]=s2[i2][0];
                        s3[i3][1]=s2[i2][1];
                        s3[i3][2]=s2[i2][2]+s1[i1][2];
                        i3++;
                        i1++;
                        i2++;
                    } else if (s1[i1][1]<s2[i2][1]){
                        s3[i3][0]=s1[i1][0];
                        s3[i3][1]=s1[i1][1];
                        s3[i3][2]=s1[i1][2];
                        i3++;
                        i1++;
                    }else {
                         s3[i3][0]=s2[i2][0];
                        s3[i3][1]=s2[i2][1];
                        s3[i3][2]=s2[i2][2];
                        i3++;
                        i2++;
                    }
                } else if (s1[i1][0]<s2[i2][0]){
                        s3[i3][0]=s1[i1][0];
                        s3[i3][1]=s1[i1][1];
                        s3[i3][2]=s1[i1][2];
                        i3++;
                        i1++;
                } else {
                    s3[i3][0]=s2[i2][0];
                        s3[i3][1]=s2[i2][1];
                        s3[i3][2]=s2[i2][2];
                        i3++;
                        i2++;
                }
            }
            while(i1<=counter1){
                s3[i3][0]=s1[i1][0];
                s3[i3][1]=s1[i1][1];
                s3[i3][2]=s1[i1][2];
                i3++;
                i1++;
            }
            while(i2<=counter1){
                s3[i3][0]=s2[i2][0];
                s3[i3][1]=s2[i2][1];
                s3[i3][2]=s2[i2][2];
                i3++;
                i2++;
            }
        } else cout<<"addition not possible ";
        s3[0][2]=i3-1;
    }

    for(int i=0 ; i<i3; i++){
        cout<<s3[i][0]<<"\t"<<s3[i][1]<<"\t"<<s3[i][2]<<endl;
    }
    return 0; 
}