class Solution {
public:
    bool dfs_no_cycle(int node, unordered_map<int, vector<int>> &graph, vector<int> &states,
                        vector<int> &res) {
       int state = states[node];
       if (state == 2) return true;
       else if (state == 1) return false;

       states[node] = 1;

       for (auto nbr : graph[node]) {
            if(!dfs_no_cycle(nbr, graph, states, res)) {
                return false;
            }
       }
       states[node] = 2;
       res.push_back(node);
       return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        for (auto vertex : prerequisites) {
            graph[vertex[0]].push_back(vertex[1]);
        }
        // unvisited = 0;
        // visiting = 1;
        // visited = 2;
        vector<int> states(numCourses, 0);
        vector<int> res;
        for (int course = 0; course<numCourses; course++) {
            if(!dfs_no_cycle(course, graph, states, res)) {
                return vector<int>();
            }
        }
        return res;
    }
};
