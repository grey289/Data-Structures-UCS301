#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
string connector(string st1,string st2) {
    string result = st1 + st2;
    return result;

}
int main()
{
    cout<<"enter 2 strings(words)"<<endl;
    string str1,str2;
    cin>>str1>>str2;
    string result=str1+ str2;
    cout<<"result is "<<result;
    return 0; 
}