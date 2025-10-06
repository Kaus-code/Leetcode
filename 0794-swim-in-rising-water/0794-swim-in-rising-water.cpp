class Solution {
public:
    bool check(int mid,vector<vector<int>>& grid,int n){
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n,false)); 
        if(grid[0][0]<=mid)q.push({0,0});
        vis[0][0] = true;
        vector<pair<int,int>> dir = {{1,0},{0,1},{0,-1},{-1,0}}; 
        while(!q.empty()){
            auto [i,j] = q.front();q.pop();
            if(i==n-1 && j==n-1) return true;
            for(auto [d1,d2]:dir){
                int n1 = d1+i,n2 = j+d2;
                if(n1>=0 && n2>=0 && n1<n && n2<n && grid[n1][n2]<=mid && !vis[n1][n2]){
                    q.push({n1,n2});
                    vis[n1][n2] = true;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int s = 0;
        int ans  = 0;
        int n =grid.size();
        int e = (n*n);
        while(s<=e){
            int mid = s+(e-s)/2;
            if(check(mid,grid,n)){
                ans = mid;
                e = mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
/*
BFS,pq,set;
*/