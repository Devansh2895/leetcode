class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int index = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (i + nums[i] >= index) {
                index = i;
            }
        }
        return index == 0;
    }
};
