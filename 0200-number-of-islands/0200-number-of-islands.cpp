class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j, vector<vector<bool>>& vis,int &c){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || j>=m || j<0 || i<0 || vis[i][j] || grid[i][j]=='0') return;
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        vis[i][j] = true;
        for(auto [a,b]:dir){
            dfs(grid,i+a,j+b,vis,c);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c= 0;

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(grid,i,j,vis,c);
                    c++;
                }
            }
        }
        return c;
    }
};