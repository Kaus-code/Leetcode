class Solution {
public:
    int n;
    int delr[4] = {-1, 1, 0, 0};
    int delc[4] = {0, 0, -1, 1};

    bool check(vector<vector<int>>& safeness, int mid) {
        if (safeness[0][0] < mid || safeness[n-1][n-1] < mid) return false;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1) return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + delr[i];
                int nc = c + delc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    if (safeness[nr][nc] >= mid) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> safeness(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    safeness[i][j] = 0; 
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + delr[i];
                int nc = c + delc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && safeness[nr][nc] == -1) {
                    safeness[nr][nc] = safeness[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        int s = 0;
        int e = 2 * n;
        int ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (check(safeness, mid)) {
                ans = mid;    
                s = mid + 1;
            } else {
                e = mid - 1;  
            }
        }

        return ans;
    }
};