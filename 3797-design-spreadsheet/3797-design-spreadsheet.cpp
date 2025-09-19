class Spreadsheet {
public:
    vector<vector<int>> arr;
    Spreadsheet(int rows) {
        arr = vector<vector<int>>(rows, vector<int>(26, 0));
    }

    int check(string s) {
        if (s.empty()) return 0; // avoid stoi crash

        char c = s[0];
        if (c >= 'A' && c <= 'Z') { // it's a cell reference
            if (s.size() == 1) return 0; // invalid cell like "A"

            int col = c - 'A';
            int row = stoi(s.substr(1))-1;
            
            if (row >= arr.size() || col >= 26) return 0; // out of bounds safe
            return arr[row][col];
        } else {
            return stoi(s); // number
        }
    }

    void setCell(string cell, int value) {
        if (cell.size() < 2) return; // invalid cell name
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1))-1;
        if (row < arr.size() && col < 26)
            arr[row][col] = value;
    }

    void resetCell(string cell) {
        if (cell.size() < 2) return;
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1))-1;
        if (row < arr.size() && col < 26)
            arr[row][col] = 0;
    }

    int getValue(string f) {
        int n = f.size();
        string token = "";
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            if (i == n || f[i] == '+') {
                if (!token.empty()) {
                    sum += check(token);
                    token = "";
                }
            } else {
                token += f[i];
            }
        }
        return sum;
    }
};
