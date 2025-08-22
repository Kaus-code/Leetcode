class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int c = 0;
        bool found = true;
        for(int i =0;i<m && found;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    found = false;
                    break;
                }
            }
            if(found)c++;
        }
        found = true;
        for(int i =m-1;i>=0 && found;i--){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    found = false;
                    break;
                }
            }
            if(found)c++;
        }
        int d= 0;
        found = true;
        for(int j =0;j<n && found;j++){
            for(int i =0;i<m;i++){
                if(grid[i][j]==1){
                    found = false;
                    break;
                }
            }
            if(found)d++;
        }
        found = true;
        for(int j =n-1;j>=0 && found;j--){
            for(int i =0;i<m;i++){
                if(grid[i][j]==1){
                    found =false;
                    break;
                    
                }
            }
            if(found)d++;
        }
        if(c>=m && d>=n){
            c=m-1;
            d=n-1;
        }
        int temp1 = m-c;
        int temp2 = n-d;
        return temp1*temp2;
    }
};