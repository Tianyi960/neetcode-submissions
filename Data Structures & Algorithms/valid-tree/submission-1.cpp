class Solution {
public:
    bool dfs(int node, int parent,
             vector<vector<int>>& graph,
             vector<bool>& visited){
        if(visited[node]) return false;
        visited[node] = true;

        for (int nei : graph[node]) {
            if (nei == parent) continue;

            if (!dfs(nei, node, graph, visited)) {
                return false;
            }
        }

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> graph(n);

        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> visited(n, false);

        if (!dfs(0, -1, graph, visited)) {
            return false;
        }
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
};
