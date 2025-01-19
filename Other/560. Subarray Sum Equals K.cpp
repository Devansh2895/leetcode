class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, preSum = 0;
        // Map to store the preSum and it's frequency
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int num : nums) {
            preSum += num;
            cnt += mp[preSum - k];
            mp[preSum]++;
        }

        // O(n^2) approach using a prefix sum array
        // for (int i=1; i<nums.size(); i++) {
        //     nums[i]+=nums[i-1];
        // }
        // int cnt=count(nums.begin(), nums.end(), k);
        // for(int i=1; i<nums.size(); i++) {
        //     for (int j=i; j<nums.size(); j++) {
        //         if (nums[j]-nums[i-1] == k)
        //             cnt++;
        //     }
        // }

        return cnt;
    }
};
