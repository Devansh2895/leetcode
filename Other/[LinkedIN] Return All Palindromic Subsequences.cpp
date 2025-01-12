class Solution {
public:
    unordered_set<string> findAll(string s) {
        unordered_set<string> result;
        if (s.size()==1) {
            result.insert(s);
            return result;
        }
        auto left = findAll(s.substr(0, s.size()-1));
        auto right = findAll(s.substr(1, s.size()));
        result.insert(left.begin(), left.end());
        result.insert(right.begin(), right.end());

        if(s[0] == s[s.size()-1]) {
            auto subset = findAll(s.substr(1, s.size()-1));
            auto head = s.substr(0,1);
            for (auto palin : subset) {
                result.insert(head + palin + head);
            }
            result.insert(head + head);
        }
        return result;
    }
    int countPalindromicSubsequences(string s) {
        return findAll(s).size();
    }
};
