class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j, vector<vector<bool>>& vis,int& a){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || j>=m || j<0 || i<0 || vis[i][j] || grid[i][j]==0) return;
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        vis[i][j] = true;
            a++;
        for(auto [aa,b]:dir){
            dfs(grid,i+aa,j+b,vis,a);

        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int maxi = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    int a = 0;
                    dfs(grid,i,j,vis,a);
                    maxi = max(maxi,a);
                }
            }
        }
        return maxi;
    }
};