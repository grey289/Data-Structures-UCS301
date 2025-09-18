#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool areAnagrams(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;

    vector<int> freq(26, 0); // for lowercase English letters

    for (char c : str1) freq[c - 'a']++;
    for (char c : str2) freq[c - 'a']--;

    for (int count : freq) {
        if (count != 0) return false;
    }
    return true;
}

int main() {
    string str1 = "listen";
    string str2 = "silent";
    string str3 = "hello";

    cout << str1 << " & " << str2 << " -> "
         << (areAnagrams(str1, str2) ? "YES" : "NO") << endl;

    cout << str1 << " & " << str3 << " -> "
         << (areAnagrams(str1, str3) ? "YES" : "NO") << endl;

    return 0;
}