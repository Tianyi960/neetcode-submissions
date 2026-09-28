class Solution {
public:
    void dfs(int n, vector<vector<int>>& graph, vector<bool>& visited){
        visited[n] = true;
        for(int nei : graph[n]){
            if (!visited[nei]) {
                dfs(nei, graph, visited);
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        for(int skip = 0; skip < edges.size(); skip++){
            vector<vector<int>> graph(n + 1);
            for (int i = 0; i < edges.size(); i++) {
                if (i == skip) continue;

                int a = edges[i][0];
                int b = edges[i][1];

                graph[a].push_back(b);
                graph[b].push_back(a);
            }
            vector<bool> visited(n+1, false);
            dfs(1, graph, visited);

            bool connected = true;

            for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                    connected = false;
                    break;
                }
            }

            if (connected) {
                ans = edges[skip];
            }
            
        }

        return ans;

    }
};
