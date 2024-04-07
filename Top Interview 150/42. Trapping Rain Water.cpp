class Solution {
public:
    static bool reverse_order(int a, int b) { return a > b; }
    int trap(vector<int>& heights) {
        if (is_sorted(heights.begin(), heights.end(), reverse_order))
            return 0;

        int start = 0, res = 0, sum = 0, n = heights.size();
        int max_ind = distance(heights.begin(),
                               max_element(heights.begin(), heights.end()));
        for (int i = 1; i <= max_ind; ++i) {
            if (heights[i] >= heights[start]) {
                res +=
                    (i - start - 1) * (min(heights[start], heights[i])) - sum;
                start = i;
                sum = 0;
            } else {
                sum += heights[i];
            }
        }

        if (max_ind != n - 1) {
            start = n - 1;
            sum = 0;
            for (int i = n - 2; i >= max_ind; --i) {
                if (heights[i] >= heights[start]) {
                    res += (start - i - 1) * (min(heights[start], heights[i])) -
                           sum;
                    start = i;
                    sum = 0;
                } else {
                    sum += heights[i];
                }
            }
        }

        return res;
    }
};
