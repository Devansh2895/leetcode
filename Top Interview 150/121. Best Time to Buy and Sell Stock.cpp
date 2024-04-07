class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_ele = prices[0], n = prices.size(), diff = 0;
        if (n == 1)
            return 0;
        for (int e : prices) {
            if (e < min_ele)
                min_ele = e;
            else
                diff = max(diff, e - min_ele);
        }
        return diff;
    }
};
