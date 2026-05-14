class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // 1. Initial setup
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j}); // Push all initially rotten oranges
                } else if (grid[i][j] == 1) {
                    fresh++; // Count fresh oranges
                }
            }
        }

        // If there are no fresh oranges, it takes 0 minutes
        if (fresh == 0) return 0;

        int t = -1; // Start at -1 because the first level is "Minute 0"
        
        // Direction vectors for Up, Down, Left, Right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // 2. BFS
        while (!q.empty()) {
            int size = q.size(); // Fix the size for this "minute"
            t++;
            
            for (int i = 0; i < size; i++) {
                pair<int, int> curr = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = curr.first + dx[d];
                    int ny = curr.second + dy[d];

                    // Check boundaries and if the neighbor is a fresh orange
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; // Mark as rotten (acts as "visited")
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        // 3. If fresh oranges remain, they were unreachable
        return (fresh == 0) ? t : -1;
    }
};