/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void printAdjacencyList(Node* node) {
        if (!node) {
            cout << "[]" << endl;
            return;
        }

        unordered_map<int, bool> visited; // To track visited nodes
        vector<vector<int>> adjacencyList; // To store adjacency list

        // Helper function to traverse the graph and populate adjacency list
        function<void(Node*)> dfs = [&](Node* current) {
            if (visited[current->val]) return;

            visited[current->val] = true;
            vector<int> neighborsList;

            for (Node* neighbor : current->neighbors) {
                neighborsList.push_back(neighbor->val);
            }

            adjacencyList.push_back(neighborsList);

            for (Node* neighbor : current->neighbors) {
                dfs(neighbor);
            }
        };

        dfs(node);

        // Print the adjacency list in the required format
        cout << "[";
        for (size_t i = 0; i < adjacencyList.size(); ++i) {
            cout << "[";
            for (size_t j = 0; j < adjacencyList[i].size(); ++j) {
                cout << adjacencyList[i][j];
                if (j != adjacencyList[i].size() - 1) cout << ",";
            }
            cout << "]";
            if (i != adjacencyList.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }

    void recurse(Node* node, Node* &clonedNode, unordered_map<int, Node*> &visited) {
        visited[node->val] = clonedNode;
        for (auto neighbor : node->neighbors) {
            if (visited.find(neighbor->val) == visited.end()) {
                Node* clone_neighbor = new Node(neighbor->val);
                clonedNode->neighbors.push_back(clone_neighbor);
                recurse(neighbor, clone_neighbor, visited);
            } else {
                clonedNode->neighbors.push_back(visited[neighbor->val]);
            }
        }
        return;
    }

    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        };
        unordered_map<int, Node*> visited;
        Node* clonedNode = new Node(node->val);
        recurse(node, clonedNode, visited);
        // printAdjacencyList(node);
        // printAdjacencyList(clonedNode);
        return clonedNode;
    }
};
