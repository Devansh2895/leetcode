class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int i = 0, j = 1, res = 0;
        // map to store the char seen till now and it's index
        // will be updated when seen again
        unordered_map<char, int> mp;
        mp[s[0]] = 0;
        while (j < s.size()) {
            if (mp.find(s[j]) != mp.end()) {
                res = max(res, j - i);
                i = max(mp[s[j]] + 1, i);
            }
            mp[s[j]] = j;
            j++;
        }
        res = max(res, j - i);
        return res;
    }
};
