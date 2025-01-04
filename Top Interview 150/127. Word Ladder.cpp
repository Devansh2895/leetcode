class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        int m = wordList.size();
        int n = wordList[0].size();
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        int ans = 0;
        unordered_map<string, int> visited;
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = 1;
        while (!q.empty()) {
            int s = q.size();
            ans++;
            while (s--) {
                string word = q.front();
                q.pop();
                if (word == endWord) return ans;
                for (int i=0; i<n; i++) {
                    char origC = word[i];
                    for (char c='a'; c<='z'; c++) {
                        word[i] = c;
                        if (wordSet.find(word) != wordSet.end() && !visited[word]) {
                            visited[word] = 1;
                            q.push(word);
                        }
                    }
                    word[i] = origC;
                }
            }
        }
        return 0;
    }
};
