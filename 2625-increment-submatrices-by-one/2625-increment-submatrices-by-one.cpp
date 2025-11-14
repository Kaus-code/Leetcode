class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> grid (n,vector<int> (n,0));
        for(auto temp:queries){
            for(int i = temp[0];i<=temp[2];i++){
                for(int j = temp[1];j<=temp[3];j++){
                    grid[i][j]++;
                }
            }
        }
        return grid;
    }
};