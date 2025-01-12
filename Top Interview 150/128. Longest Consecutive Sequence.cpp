class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans=0;
        for(int x:st) {
            if(st.find(x-1) == st.end()) {
                int j=x;
                while(st.find(j) != st.end())
                    j++;
                ans = max(ans, j-x);
            }
        }
        return ans;
    }
};
