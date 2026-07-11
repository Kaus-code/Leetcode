class Solution {
public:
     typedef pair<int,int> p;
     vector<int> parent;
     vector<int> rank;

     int find(int x)
     {
        if(x==parent[x]) return x;

        return parent[x]=find(parent[x]);
     }
     void Union(int x, int y)
     {
        int x_parent=find(x);
        int y_parent=find(y);

        if(x_parent==y_parent) return;
        if(rank[x_parent]>rank[y_parent])
        {
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent])
        {
            parent[x_parent]=y_parent;
        }
       else
        {
         parent[x_parent]=y_parent;
         rank[y_parent]++;
        }
     }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
     int ans=0;
     parent.resize(n);
     rank.assign(n,0);
     
     for(int i=0;i<n;i++)
     {
        parent[i]=i;
     }

//Union all edges
   for(auto &e:edges)
   {
Union(e[0],e[1]);
   }
    unordered_map<int,int> vertices;
    //count vertices
    for(int i=0;i<n;i++)
    {
vertices[find(i)]++;
    }
unordered_map<int,int>edgecount;
//count edges
for(auto&e:edges)
{
edgecount[find(e[0])]++;
}

for(auto &[root,v]:vertices)
{
    int expected=v*(v-1)/2;

    if(edgecount[root]==expected)
    {
        ans++;
    }
}
return ans;
    }
};