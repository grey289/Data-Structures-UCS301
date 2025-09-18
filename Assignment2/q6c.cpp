
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
    //Taking input of matrix 2
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
    // Transpose (simple sort after swapping)
    for(int i=1;i<=counter2;i++){
        int temp = s2[i][0];
        s2[i][0] = s2[i][1];
        s2[i][1] = temp;
    }

    // Bubble sort by row then col
    for(int i=1;i<=counter2;i++){
        for(int j=1;j<=counter2-i;j++){
            if(s2[j][0] > s2[j+1][0] || (s2[j][0]==s2[j+1][0] && s2[j][1] > s2[j+1][1])){
                for(int k=0;k<3;k++){
                    int tmp = s2[j][k];
                    s2[j][k] = s2[j+1][k];
                    s2[j+1][k] = tmp;
                }
            }
        }
    }

    // Print transpose
    cout << "Transpose sparse matrix:\n";
    cout << c2 << "\t" << r2 << "\t" << counter2 << "\n";
    for(int i=1;i<=counter2;i++)
        cout << s2[i][0] << "\t" << s2[i][1] << "\t" << s2[i][2] << "\n";
    if(c1==r2){
        cout<<"matrix multiplication is possible. Do you want to multiply? (yes=1 no=0)"<<endl;
        int ans=0;
        cin>>ans;
        if(ans==1){
            int s3[100][3];
            s3[0][0]=r1;
            s3[0][1]=c2;
            int i1=1,i2=1,i3=1;
            while(i1<=s1[0][2] && i2<=s2[0][2]){
                int i3=1;
                
                int temp=0;
                if(s1[i1][0]==s2[i2][0]){
                    if(s1[i1][1]==s2[i2][1])
                    temp=temp+s1[i1][1]*s2[i2][1];
                    i1++;
                    i2++;
                } else if(s1[i1][0]<s2[i2][0]) {
                    i1++;
                } else i2++;
                if (temp!=0){
                    s3[i3][0];//value of row index;
                s3[i3][1];//value of coulmn index
                s3[i3][2]=temp;}
            }
            
            
        }
    }
    return 0;
}
/*
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
    
    cout << "Enter elements of matrix 1:" << endl;
    // Read matrix and build sparse form
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cin >> m1[i][j];
            if(m1[i][j] != 0){
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
    
    // Printing matrix 1
    cout << "Matrix 1:" << endl;
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cout << m1[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Print sparse form of matrix 1
    cout << "Sparse matrix 1 form:" << endl;
    cout << "Row\tCol\tValue" << endl;
    for(int i=0; i<=counter1; i++)
        cout << s1[i][0] << "\t" << s1[i][1] << "\t" << s1[i][2] << endl;
    cout << endl;
    
    // Taking input of matrix 2
    int r2, c2;
    cout << "Enter rows for matrix 2: ";
    cin >> r2;
    cout << "Enter cols for matrix 2: ";
    cin >> c2;
    
    int m2[r2][c2];
    int s2[100][3];
    int counter2 = 0;
    
    cout << "Enter elements of matrix 2:" << endl;
    // Read matrix and build sparse form
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            cin >> m2[i][j];
            if(m2[i][j] != 0){
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
    
    // Printing matrix 2
    cout << "Matrix 2:" << endl;
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            cout << m2[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Print sparse form of matrix 2
    cout << "Sparse matrix 2 form:" << endl;
    cout << "Row\tCol\tValue" << endl;
    for(int i=0; i<=counter2; i++)
        cout << s2[i][0] << "\t" << s2[i][1] << "\t" << s2[i][2] << endl;
    cout << endl;
    
    // Create transpose of matrix 2 for multiplication
    int s2_transpose[100][3];
    s2_transpose[0][0] = c2; // rows of transpose
    s2_transpose[0][1] = r2; // cols of transpose
    s2_transpose[0][2] = counter2; // non-zero elements
    
    // Copy and swap row/col indices for transpose
    for(int i=1; i<=counter2; i++){
        s2_transpose[i][0] = s2[i][1]; // col becomes row
        s2_transpose[i][1] = s2[i][0]; // row becomes col
        s2_transpose[i][2] = s2[i][2]; // value remains same
    }
    
    // Sort transpose by row then column
    for(int i=1; i<=counter2; i++){
        for(int j=1; j<=counter2-i; j++){
            if(s2_transpose[j][0] > s2_transpose[j+1][0] || 
               (s2_transpose[j][0] == s2_transpose[j+1][0] && s2_transpose[j][1] > s2_transpose[j+1][1])){
                for(int k=0; k<3; k++){
                    int tmp = s2_transpose[j][k];
                    s2_transpose[j][k] = s2_transpose[j+1][k];
                    s2_transpose[j+1][k] = tmp;
                }
            }
        }
    }
    
    // Print transpose
    cout << "Transpose of matrix 2:" << endl;
    cout << "Row\tCol\tValue" << endl;
    cout << s2_transpose[0][0] << "\t" << s2_transpose[0][1] << "\t" << s2_transpose[0][2] << endl;
    for(int i=1; i<=counter2; i++)
        cout << s2_transpose[i][0] << "\t" << s2_transpose[i][1] << "\t" << s2_transpose[i][2] << endl;
    cout << endl;
    
    // Matrix multiplication
    if(c1 == r2){
        cout << "Matrix multiplication is possible. Do you want to multiply? (yes=1 no=0)" << endl;
        int ans = 0;
        cin >> ans;
        if(ans == 1){
            int result[100][3];
            result[0][0] = r1;
            result[0][1] = c2;
            int result_count = 0;
            
            // For each row of first matrix
            for(int i=0; i<r1; i++){
                // For each column of second matrix
                for(int j=0; j<c2; j++){
                    int sum = 0;
                    
                    // Calculate dot product of row i of matrix1 and column j of matrix2
                    for(int k=0; k<c1; k++){ // c1 = r2
                        int val1 = 0, val2 = 0;
                        
                        // Find value at position (i,k) in matrix 1
                        for(int x=1; x<=counter1; x++){
                            if(s1[x][0] == i && s1[x][1] == k){
                                val1 = s1[x][2];
                                break;
                            }
                        }
                        
                        // Find value at position (k,j) in matrix 2
                        for(int x=1; x<=counter2; x++){
                            if(s2[x][0] == k && s2[x][1] == j){
                                val2 = s2[x][2];
                                break;
                            }
                        }
                        
                        sum += val1 * val2;
                    }
                    
                    // If sum is non-zero, add to result
                    if(sum != 0){
                        result_count++;
                        result[result_count][0] = i;
                        result[result_count][1] = j;
                        result[result_count][2] = sum;
                    }
                }
            }
            
            result[0][2] = result_count;
            
            // Print result
            cout << "Result of multiplication (sparse form):" << endl;
            cout << "Row\tCol\tValue" << endl;
            for(int i=0; i<=result_count; i++){
                cout << result[i][0] << "\t" << result[i][1] << "\t" << result[i][2] << endl;
            }
            
            // Print result as normal matrix
            cout << "\nResult matrix:" << endl;
            for(int i=0; i<r1; i++){
                for(int j=0; j<c2; j++){
                    int value = 0;
                    for(int k=1; k<=result_count; k++){
                        if(result[k][0] == i && result[k][1] == j){
                            value = result[k][2];
                            break;
                        }
                    }
                    cout << value << "\t";
                }
                cout << endl;
            }
        }
    } else {
        cout << "Matrix multiplication is not possible. Number of columns in first matrix must equal number of rows in second matrix." << endl;
    }
    
    return 0;
}
*/