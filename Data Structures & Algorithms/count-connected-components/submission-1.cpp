class Solution {
public:
    void dfs(int n, vector<vector<int>>& graph, vector<bool>& visited){
        visited[n] = true;
        for (int nei : graph[n]) {
            if (!visited[nei]) {
                dfs(nei, graph, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        int ans = 0;
        for(auto& edge : edges){
            int a = edge[0];
            int b = edge[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited);
                ans++;
            }
        }
       
        
        return ans;
    }
};
