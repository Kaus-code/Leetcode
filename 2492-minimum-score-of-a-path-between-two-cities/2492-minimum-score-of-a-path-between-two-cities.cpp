class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        queue<int> q;
        vector<bool> vis(n + 1, false);
        
        q.push(1);
        vis[1] = true;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto& [neighbor, weight] : adj[node]) {
                ans = min(ans, weight);
                
                if (!vis[neighbor]) {
                    vis[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return ans;
    }
};