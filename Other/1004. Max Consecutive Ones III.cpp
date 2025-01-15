// This question can be converted into:
// Maximum sub-array length with at most k zeroes
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zros = 0, res = 0, l = 0, i;
        for (i=0; i<nums.size();i++) {
            if (nums[i] == 0) {
                zros++;
                res = max(res, i-l);
                while(zros>k && l<=i) {
                    if (nums[l]==1){
                        l++;
                    } else {
                        l++;
                        zros--;
                    }
                }
            }
        }
        res = max(res, i-l);
        return res;
    }
};
