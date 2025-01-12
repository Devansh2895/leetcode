class Solution {
public:
    int maxArea(vector<int>& height) {
        int lt = 0, c_max = 0;
        int rt = height.size() - 1;
        while (rt > lt) {
            int h = min(height[lt], height[rt]);
            int l = rt - lt;
            c_max = max(c_max, l * h);
            if (height[rt] <= height[lt])
                --rt;
            else
                ++lt;
        }
        return c_max;
    }
};
