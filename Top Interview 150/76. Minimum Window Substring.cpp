class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cur;
        unordered_map<char, int> req;
        int count = t.size();

        for(char c:t) {
            req[c]++;
        }
        int i;
        for(i=0; i<s.size() && count!=0; i++) {
            if(req[s[i]]) {
                cur[s[i]]++;
                if(cur[s[i]] <= req[s[i]]) {
                    count--;
                }
            }
        }
        if (count!=0) return "";
        int right = i-1;
        
        int left = 0;
        while(!req[s[left]] || cur[s[left]]>req[s[left]]) {
            cur[s[left]]--;
            left++;
        }
        int min_length = right - left;
        
        i=left;
        int j=right+1;
        while(j<s.size()) {
            if(req[s[j]]) {
                cur[s[j]]++;
                while(!req[s[i]] || cur[s[i]]>req[s[i]]) {
                    cur[s[i]]--;
                    i++;
                }
                if((j-i) < min_length) {
                    min_length = j-i;
                    left = i;
                    right = j;
                }
            }
            j++;
        }
            
        return s.substr(left, right-left+1);
    }
};
