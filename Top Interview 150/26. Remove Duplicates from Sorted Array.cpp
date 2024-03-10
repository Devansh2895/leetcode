class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int k = 1;
        for (int i=0, j=1; i<size-1 && j<size; ++i) {
            if (nums[i] < nums[i+1]) {
                nums[j] = nums[i+1];
                ++j;
                ++k;
            }
        }
        return k;
    }
};
