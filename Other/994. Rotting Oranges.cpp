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
        vector<vector<int>> visited(m, vector<int>(n));
        queue<vector<int>> q;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1)
                    num1s++;
                else if (grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        if (num1s == 0) return 0;
        int mnt=0;
        while (!q.empty()) {
            int s = q.size();
            while(s--) {
                auto idx = q.front();
                int i = idx[0];
                int j = idx[1];
                q.pop();
                visited[i][j] = 1;
                int ai;
                int aj;
                for (int a=0; a<4; a++) {
                    ai = i+nx[a];
                    aj = j+ny[a];

                    if ((inGrid(ai, aj, m, n) && grid[ai][aj] == 1) && visited[ai][aj]==0) {
                        visited[ai][aj] = 1;
                        grid[ai][aj] = 2;
                        q.push({ai,aj});
                    }
                }
            }
            cout<<endl;
            mnt++;
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return mnt-1;
    }
};
