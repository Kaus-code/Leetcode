class Solution {
    private:
    bool check(vector<vector<bool>> &board,int row,int col){
        int n = board.size();
        int i,j;
        for(i = col-1;i >= 0;i--){
            if(board[row][i]) return false;
        }
        for(i = row-1;i >= 0;i--){
            if(board[i][col]) return false;
        }
        i = row-1,j = col-1;
        
        while(i >= 0 && j >= 0){
            if(board[i--][j--]) return false;
        }
        
        i = row-1,j = col+1;
        while(i >= 0 && j < n){
            if(board[i--][j++]) return false;
        }
        return true;
    }
    void solve(vector<vector<bool>> &board,int row,int n,vector<int> temp,vector<vector<string>> &ans){
        if(row >= n){
            vector<string> str;
            for(auto& t : temp){
                string s = "";
                for(int i = 1;i <= n;i++){
                    if(i == t) s.push_back('Q');
                    else s.push_back('.');
                }
                str.push_back(s);
            }
            ans.push_back(str);
            return;
        }
        for(int i = 0;i < n;i++){
            if(check(board,row,i)){
                board[row][i] = true;
                temp.push_back(i+1);
                solve(board,row+1,n,temp,ans);
                temp.pop_back();
                board[row][i] = false; 
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> board(n,vector<bool>(n,false));
        vector<vector<string>> ans;
        solve(board,0,n,{},ans);
        return ans;
    }
};