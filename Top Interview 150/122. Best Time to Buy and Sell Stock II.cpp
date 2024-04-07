class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1)
            return 0;
        int buy, diff = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] < prices[i - 1]) {
                buy = prices[i];
            } else {
                diff += prices[i] - prices[i - 1];
            }
        }
        return diff;
    }
};
