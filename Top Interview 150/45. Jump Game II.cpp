class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        int reach = nums[0];
        if (reach >= n - 1) {
            return 1;
        }

        int count = 1;
        for (int i = 0; i < n - 1;) {
            int k = reach;
            for (int j = i + 1; j <= k; ++j) {
                if (j + nums[j] >= reach) {
                    reach = j + nums[j];
                }
            }
            i = k;
            ++count;
            if (reach >= n - 1) {
                return count;
            }
        }
        return count;
    }
};
