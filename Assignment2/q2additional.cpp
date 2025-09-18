#include <iostream>
#include <string>
using namespace std;

bool canSplit(const string &s) {
    int n = s.size();

    // Try every split into A | B | C
    for (int i = 1; i < n - 1; i++) {       // first cut
        for (int j = i + 1; j < n; j++) {   // second cut
            string A = s.substr(0, i);
            string B = s.substr(i, j - i);
            string C = s.substr(j);

            // Check conditions
            if ((B.find(A) != string::npos && C.find(A) != string::npos) || 
                (A.find(B) != string::npos && C.find(B) != string::npos) || 
                (A.find(C) != string::npos && B.find(C) != string::npos)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s1 = "abcabc";
    string s2 = "aaa";
    string s3 = "abcd";

    cout << s1 << " -> " << (canSplit(s1) ? "YES" : "NO") << endl;
    cout << s2 << " -> " << (canSplit(s2) ? "YES" : "NO") << endl;
    cout << s3 << " -> " << (canSplit(s3) ? "YES" : "NO") << endl;

    return 0;
}