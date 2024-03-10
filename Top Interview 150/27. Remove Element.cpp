class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int j = size-1;
        int count = 0;
        for (int i=0; i<=j; ++i) {
            while (j>=0 && nums[j]==val) {
                nums[j]=-1;
                ++count;
                --j;
            }
            if (nums[i] == val) {
                ++count;
                nums[i] = nums[j];
                nums[j] = -1;
                --j;
            }
        }
        return size-count;
    }
};
