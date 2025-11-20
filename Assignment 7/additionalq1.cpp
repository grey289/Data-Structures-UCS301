#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int> mpp;
       for (int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
       } 
       int max=-1;
       int ans;
       for(auto it:mpp){
        if(it.second>max){ max=it.second; ans=it.first;}
       }
       return ans;
    }
};