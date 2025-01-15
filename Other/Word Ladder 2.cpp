// Problem Link: https://www.geeksforgeeks.org/problems/word-ladder-ii/1
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return vector<vector<string>>();
        }
        int m = wordList.size();
        int n = wordList[0].size();
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        queue<vector<string>> q;

        q.push({beginWord});
        wordSet.erase(beginWord);
        while (!q.empty()) {
            int s = q.size();
            unordered_set<string> tempSet;
            while (s--) {
                auto curList = q.front();
                string word = curList.back();
                q.pop();
                if (word == endWord) ans.push_back(curList);
                for (int i=0; i<n; i++) {
                    char origC = word[i];
                    for (char c='a'; c<='z'; c++) {
                        word[i] = c;
                        if (wordSet.find(word) != wordSet.end() ||
                                tempSet.find(word) != tempSet.end()) {
                            curList.push_back(word);
                            q.push(curList);
                            curList.pop_back();
                            tempSet.insert(word);
                            wordSet.erase(word);
                        }
                    }
                    word[i] = origC;
                }
            }
        }
        return ans;
    }
};
