class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // To store the first occurrence of each prefix sum
        unordered_map<int, int> mp;
        // Base case for prefix sum of 0 before the array starts
        mp[0] = -1;

        int res = 0;
        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Treat 0 as -1 for calculation purposes
            prefixSum += (nums[i] == 0) ? -1 : 1;

            if (mp.find(prefixSum) != mp.end())
                res = max(res, i - mp[prefixSum]);
            else
                mp[prefixSum] = i; 
        }

        return res;
    }
};
