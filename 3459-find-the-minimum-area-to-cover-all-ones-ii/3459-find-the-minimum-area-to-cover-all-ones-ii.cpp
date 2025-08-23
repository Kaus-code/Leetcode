class Solution {
public:
    int minArea(int startrow, int endrow, int startcol, int endcol, vector<vector<int>>& grid) {
        int minrow = endrow;
        int maxrow = -1;
        int mincol = endcol;
        int maxcol = -1;
        
        for(int i = startrow; i < endrow; i++) {
            for(int j = startcol; j < endcol; j++) {
                if(grid[i][j] == 1) {
                    minrow = min(minrow, i);
                    maxrow = max(maxrow, i);
                    mincol = min(mincol, j);
                    maxcol = max(maxcol, j);
                }
            }
        }
        
        // Return 0 if no 1s found in this region
        if(maxrow == -1) return 0;
        
        return (maxrow - minrow + 1) * (maxcol - mincol + 1);
    }
    
    int minimumSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        
        // All possible L-shaped divisions
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                // Pattern 1: Top + Bottom-Left + Bottom-Right
                int top = minArea(0, i, 0, n, grid);
                int bottomLeft = minArea(i, m, 0, j, grid);
                int bottomRight = minArea(i, m, j, n, grid);
                if(top && bottomLeft && bottomRight) {
                    ans = min(ans, top + bottomLeft + bottomRight);
                }
                
                // Pattern 2: Top-Left + Top-Right + Bottom
                int topLeft = minArea(0, i, 0, j, grid);
                int topRight = minArea(0, i, j, n, grid);
                int bottom = minArea(i, m, 0, n, grid);
                if(topLeft && topRight && bottom) {
                    ans = min(ans, topLeft + topRight + bottom);
                }
                
                // Pattern 3: Left + Top-Right + Bottom-Right
                int left = minArea(0, m, 0, j, grid);
                int topRight2 = minArea(0, i, j, n, grid);
                int bottomRight2 = minArea(i, m, j, n, grid);
                if(left && topRight2 && bottomRight2) {
                    ans = min(ans, left + topRight2 + bottomRight2);
                }
                
                // Pattern 4: Top-Left + Right + Bottom-Left
                int topLeft2 = minArea(0, i, 0, j, grid);
                int right = minArea(0, m, j, n, grid);
                int bottomLeft2 = minArea(i, m, 0, j, grid);
                if(topLeft2 && right && bottomLeft2) {
                    ans = min(ans, topLeft2 + right + bottomLeft2);
                }
            }
        }
        
        // Horizontal divisions
        for(int split1 = 1; split1 < m; split1++) {
            for(int split2 = split1 + 1; split2 < m; split2++) {
                int top = minArea(0, split1, 0, n, grid);
                int middle = minArea(split1, split2, 0, n, grid);
                int bottom = minArea(split2, m, 0, n, grid);
                if(top && middle && bottom) {
                    ans = min(ans, top + middle + bottom);
                }
            }
        }
        
        // Vertical divisions
        for(int split1 = 1; split1 < n; split1++) {
            for(int split2 = split1 + 1; split2 < n; split2++) {
                int left = minArea(0, m, 0, split1, grid);
                int middle = minArea(0, m, split1, split2, grid);
                int right = minArea(0, m, split2, n, grid);
                if(left && middle && right) {
                    ans = min(ans, left + middle + right);
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};