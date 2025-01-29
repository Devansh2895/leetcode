class Solution {
private:
    // memo to store the minimum price for a given
    // combination of start node and # of stops left
    vector<vector<int>> memo;

    int dfs( unordered_map<int, vector<pair<int, int>>>& grid, int start, int dst, int k) {
        if (start == dst) return 0;
        if (k==-1) return 1e5;
        if (memo[start][k] != -1) return memo[start][k];
        
        int g_price = 1e5;
        for(auto x : grid[start]) {
            int c_price = x.second;
            c_price += dfs(grid, x.first, dst, k-1);
            g_price = min(g_price, c_price);
        }
        return memo[start][k] = g_price;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> grid;
        for(auto flight:flights) {
            grid[flight[0]].push_back({flight[1], flight[2]});
        }

        memo = vector(n, vector<int>(k+1, -1));
        int ans = dfs(grid, src, dst, k);
        return ans == 1e5 ? -1 : ans ;
    }
};
