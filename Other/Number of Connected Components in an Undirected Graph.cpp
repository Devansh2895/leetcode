// Problem link:
// https://neetcode.io/problems/count-connected-components

// Below is the code for the Union Find approach.
// Another approach is to get nodes from the adjacency list
// and for each node that is not visited, call DFS on it.
// Number of times you call the dfs is the answer.
class Solution {
private:
    int find(int val, vector<int> &par) {
        int res = val;
        while(par[res]!=res) {
            res = par[res];
        }
        return res;
    }
    int unionF(int n1, int n2, vector<int> &par, vector<int> &rank) {
        int p1 = find(n1, par);
        int p2 = find(n2, par);

        if (p1==p2) {
            return 0;
        }
        if (rank[p1] >= rank[p2]) {
            par[p2] = p1;
            rank[p1]++;
        } else {
            par[p1] = p2;
            rank[p2]++;
        }
        return 1;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> par(n);
        iota(par.begin(), par.end(), 0);
        vector<int> rank(n, 1);
        int ans = n;
        for(auto edge:edges) {
            ans-=unionF(edge[0], edge[1], par, rank);
        }
        return ans;
    }
};
