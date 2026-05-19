class Solution {
public:
    vector<vector<int>> ans;
    vector<int> disc, low;
    int timer = 0;
    void dfs(int node, int parent, vector<vector<int>>& adj) {
        disc[node] = low[node] = timer++;
        for(auto &nbr : adj[node]) {
            if(nbr == parent) continue;
            if(disc[nbr] == -1) {
                dfs(nbr, node, adj);
                low[node] = min(low[node], low[nbr]);
                if(low[nbr] > disc[node]) {
                    ans.push_back({node, nbr});
                }
            }
            else {
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &t : connections) {
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
        }
        disc.assign(n, -1);
        low.assign(n, -1);
        dfs(0, -1, adj);
        return ans;
    }
};