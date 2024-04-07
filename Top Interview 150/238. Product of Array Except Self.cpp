class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int num = 1;
        for (int i = 0; i < n - 1; ++i) {
            num *= nums[i];
            res[i + 1] = num;
        }
        num = 1;
        for (int i = n - 1; i > 0; --i) {
            num *= nums[i];
            res[i - 1] *= num;
        }
        return res;
    }
};
