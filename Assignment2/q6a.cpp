#include <iostream>
using namespace std;

int main(){
    int r, c;
    cout << "Enter rows: ";
    cin >> r;
    cout << "Enter cols: ";
    cin >> c;

    int m[r][c];
    int s[100][3];
    int counter = 0;

    // Read matrix and build sparse form
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> m[i][j];
            if(m[i][j]!=0){
                counter++;
                s[counter][0] = i;
                s[counter][1] = j;
                s[counter][2] = m[i][j];
            }
        }
    }
    s[0][0] = r;
    s[0][1] = c;
    s[0][2] = counter;
    //printing matrix
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<< m[i][j]<<"\t";}cout<<endl;}
    // Print sparse
    cout << "Sparse matrix form:\n";
    cout<<"row\tCol\tValue"<<endl;
    for(int i=0;i<=counter;i++)
        cout << s[i][0] << "\t" << s[i][1] << "\t" << s[i][2] << "\n";
    cout<<endl;
    // Transpose (simple sort after swapping)
    for(int i=1;i<=counter;i++){
        int temp = s[i][0];
        s[i][0] = s[i][1];
        s[i][1] = temp;
    }

    // Bubble sort by row then col
    for(int i=1;i<=counter;i++){
        for(int j=1;j<=counter-i;j++){
            if(s[j][0] > s[j+1][0] || (s[j][0]==s[j+1][0] && s[j][1] > s[j+1][1])){
                for(int k=0;k<3;k++){
                    int tmp = s[j][k];
                    s[j][k] = s[j+1][k];
                    s[j+1][k] = tmp;
                }
            }
        }
    }

    // Print transpose
    cout << "Transpose sparse matrix:\n";
    cout << c << "\t" << r << "\t" << counter << "\n";
    for(int i=1;i<=counter;i++)
        cout << s[i][0] << "\t" << s[i][1] << "\t" << s[i][2] << "\n";

    return 0;
}
