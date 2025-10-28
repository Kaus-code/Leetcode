class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {

            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < row.size(); i += 2) {
            int a = row[i] / 2;
            int b = row[i + 1] / 2;
            Union(a, b);
        }

        unordered_set<int> components;
        for (int i = 0; i < n; i++)
            components.insert(find(i));

        return n - components.size();
    }
};