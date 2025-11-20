
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // //finding max element for size of freq arr
        // int size=-1;
        // for(int i=0;i<costs.size();i++ ){
        //     if(costs[i]>size) size=costs[i];
        // }
        // //building freq arr
        // vector<int>costing(size+1,0);
        // for(int i=0;i<costs.size();i++){
        //     costing[costs[i]]++;
        // }
        // //building icecream arr
        // vector<int>ice;
        // for(int i=0;i<costing.size();i++){
        //     for(int k=0;k<costing[i];k++)
        //     ice.emplace_back(i);
        // }
        sort(costs.begin(),costs.end());
        int bars=0;
        for(int i=0;i<costs.size();i++){
            if(coins>=costs[i]){
                bars++;
                coins-=costs[i];
            }
        }
        return bars;
    }
};