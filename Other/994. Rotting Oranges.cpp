class Solution {
public:
    bool inGrid(int i, int j, int m, int n) {
        if (i>=0 && i<m && j>=0 && j<n)
            return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int num1s = 0;
        vector<int> nx = {0,0,1,-1};
        vector<int> ny = {1,-1,0,0};
        queue<vector<int>> q;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1)
                    ++num1s;
                else if (grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        if (num1s == 0) return 0;
        int mnt=-1;
        while (!q.empty()) {
            int s = q.size();
            while(s--) {
                auto idx = q.front();
                int i = idx[0];
                int j = idx[1];
                q.pop();
                grid[i][j] = 2;
                for (int a=0; a<4; ++a) {
                    int ai = i+nx[a];
                    int aj = j+ny[a];

                    if (inGrid(ai, aj, m, n) && grid[ai][aj] == 1) {
                        grid[ai][aj] = 2;
                        --num1s;
                        q.push({ai,aj});
                    }
                }
            }
            mnt++;
        }
        return num1s==0 ? mnt : -1;
    }
};
