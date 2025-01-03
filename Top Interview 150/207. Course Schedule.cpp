class Solution {
public:
    bool dfs_no_cycle(int node, unordered_map<int, vector<int>> &graph, vector<int> &states) {
       // unvisited = 0;
       // visiting = 1;
       // visited = 2;
       int state = states[node];
       if (state == 2) return true;
       else if (state == 1) return false;

       states[node] = 1;

       for (auto nbr : graph[node]) {
            if(!dfs_no_cycle(nbr, graph, states)) {
                return false;
            }
       }
       states[node] = 2;
       return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty()) return true;
        unordered_map<int, vector<int>> graph;
        for (auto vertex : prerequisites) {
            graph[vertex[0]].push_back(vertex[1]);
        }
        vector<int> states(numCourses, 0);
        for (int course = 0; course<numCourses; course++) {
            if (!dfs_no_cycle(course, graph, states))
                return false;
        }
        return true;
    }
};
