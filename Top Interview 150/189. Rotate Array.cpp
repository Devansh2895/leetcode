class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        vector<int> nums2(std::make_move_iterator(
            nums.end() - k), std::make_move_iterator(nums.end()));
        nums.erase(nums.end() - k, nums.end());
        nums.insert(nums.begin(), nums2.begin(), nums2.end());
        nums2.clear();
    }
};
