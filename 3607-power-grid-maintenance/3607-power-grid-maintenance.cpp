class Solution {
public:
vector<int>parent;
vector<int> rank;
int find(int x)
{
    if(x==parent[x])
    {
        return x;
    }
    return parent[x]=find(parent[x]);
}

void Union (int x,int y)
{
    int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent==y_parent)
    {
        return;
    }
    else if(rank[x_parent]> rank[y_parent])
    {
        parent[y_parent]=x_parent;
    }
    else if(rank[x_parent]< rank[y_parent])
    {
        parent[x_parent]=y_parent;
    }
    else
    {
 parent[x_parent]=y_parent;
 rank[y_parent]++;
    }
}
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
       
        parent.resize(c+1);
        rank.resize(c+1,0);
        for(int i=0;i<c+1;i++)
        {
            parent[i]=i;
        }
        // Build the connected components
        for (auto& e : connections) {
            Union(e[0], e[1]);
        }

        // For each connected component (root), we maintain a set of "online" stations
        unordered_map<int, set<int>> onlineSets;
        vector<bool> online(c + 1, true);

        for (int i = 1; i <= c; i++) {
            int root = find(i);
            onlineSets[root].insert(i);
        }

        vector<int> result;

        // Process each query
        for (auto& q : queries) {
            int type = q[0];
            int x = q[1];
            int root = find(x);

            if (type == 1) {
                // Maintenance check
                if (online[x]) {
                    result.push_back(x);
                } else {
                    if (onlineSets[root].empty())
                        result.push_back(-1);
                    else
                        result.push_back(*onlineSets[root].begin());
                }
            } else if (type == 2) {
                // Go offline
                if (online[x]) {
                    online[x] = false;
                    onlineSets[root].erase(x);
                }
            }
        }

        return result;
    }
};