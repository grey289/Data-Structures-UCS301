#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
string reverseString(string original) {
 
    string reversed = original; 
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

int main()
{
    cout<<"enter a string"<<endl;
    string str;
    cin>>str;
    string rev=reverseString(str);
    cout<<rev;
    return 0; 
}