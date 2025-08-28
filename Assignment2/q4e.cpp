#include <iostream>
using namespace std;

int main() {
    char ch;
    
    cout << "Enter a character: ";
    cin >> ch;
    
    // Check if character is uppercase
    if (ch >= 'A' && ch <= 'Z') {
        // Convert to lowercase by adding 32 (ASCII difference)
        char lowercase = ch + 32;
        cout << "Uppercase '" << ch << "' converted to lowercase: '" << lowercase << "'" << endl;
    }
    else if (ch >= 'a' && ch <= 'z') {
        cout << "'" << ch << "' is already lowercase." << endl;
    }
    else {
        cout << "'" << ch << "' is not a letter." << endl;
    }
    
    return 0;
}