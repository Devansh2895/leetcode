class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        for (int i=0, j=1; i<n-1 && j<n; ++i) {
            if (nums[i] < nums[i+1]) {
                nums[j] = nums[i+1];
                ++j;
                ++k;
            }
        }
        return k;
    }
};
