class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size=arr.size(),i=0,cnt=0;
        for(i=0;i<size;i++){
            if(arr[i]==0){
                arr.insert(arr.begin()+i,0);
                i++;
                cnt++;
            }
        }
        arr.erase(arr.end()-cnt,arr.end());
    }
};