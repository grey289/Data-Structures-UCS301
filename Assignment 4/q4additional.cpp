
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue <int> line;
        stack<int> sandies;
        for(int i=0;i<students.size();i++){
            line.push(students[i]);
            sandies.push(sandwiches[students.size()-i-1]);
        }
        int cnt=0;
        while(!line.empty()&& cnt!=line.size())
        {
            if(line.front()==sandies.top()){
                line.pop();
                sandies.pop();
                cnt=0;
            }else {
                line.push(line.front());
                line.pop();
                cnt++;
            }
        }
        return line.size();
    }
};