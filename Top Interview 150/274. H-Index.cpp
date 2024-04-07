class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 1)
            return citations[0] == 0 ? 0 : 1;

        sort(citations.begin(), citations.end());
        int max = n;
        for (int x : citations) {
            if (x >= max)
                return max;
            else
                max--;
        }
        return max;
    }
};
