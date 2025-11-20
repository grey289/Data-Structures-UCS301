#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& A, vector<int>& B, int K) {
       // Step 1: Sort both arrays in descending order
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        int N=A.size();
        // Max-heap storing: (sum, i, j)
        priority_queue< tuple<int,int,int> > pq;

        // Set to avoid repeating pairs
        set<pair<int,int>> used;

        vector<int> ans;

        // Step 2: Push the largest combination (0,0)
        pq.push({A[0] + B[0], 0, 0});
        used.insert({0,0});

        // Step 3: Extract K times
        while (K--) {

            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back(sum);

            // Move DOWN → (i+1, j)
            if (i + 1 < N && !used.count({i+1, j})) {
                pq.push({A[i+1] + B[j], i+1, j});
                used.insert({i+1, j});
            }

            // Move RIGHT → (i, j+1)
            if (j + 1 < N && !used.count({i, j+1})) {
                pq.push({A[i] + B[j+1], i, j+1});
                used.insert({i, j+1});
            }
        }

        return ans;
    
        
    }
};