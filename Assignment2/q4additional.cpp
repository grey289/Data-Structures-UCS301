class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = nums.size();
        int l = 0, h = s - 1;

        for (int i = 0; i <= h; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++;
            } 
            else if (nums[i] == 2) {
                swap(nums[i], nums[h]);
                h--;
                i--; // recheck this index because swapped element might be 0 or 2
            }
        }
    }
};