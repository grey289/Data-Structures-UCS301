#include <iostream>
#include <string>
using namespace std;

string removeVowels(string str) {
    string result = "";
    
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        // Check if character is not a vowel (both lowercase and uppercase)
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' &&
            ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U') {
            result += ch;
        }
    }
    
    return result;
}

int main() {
    string input;
    
    cout << "Enter a string: ";
    getline(cin, input);
    
    string output = removeVowels(input);
    
    cout << "String after removing vowels: " << output << endl;
    
    return 0;
}
