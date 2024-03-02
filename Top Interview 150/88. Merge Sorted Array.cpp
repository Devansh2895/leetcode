class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        if (m==0) {
            a=b;
        }

        int i, j, k = m+n-1;
        for (i = m-1, j=n-1; i >= 0 && j>=0;)
        {
            if (b[j] >= a[i]) {
                a[k] = b[j];
                --k;
                --j;
            }

            else {
                a[k] = a[i];
                --k;
                --i;
            }
        }

        while (i<0 && k>=0) {
            a[k] = b[j];
            --k;
            --j;
        }
    }
};