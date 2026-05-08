/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void buildGraph(TreeNode* root, unordered_map<int, vector<int>>& adj) {
        if (!root) return;
        
        if (root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            buildGraph(root->left, adj);
        }
        if (root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            buildGraph(root->right, adj);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_set<int> vis;
        unordered_map<int,vector<int>> adj;
        buildGraph(root,adj);
        queue<int> q;
        q.push(start);
        int c = 0;
        while(!q.empty()){
            c++;
            int sz = q.size();
            for(int  i = 0;i<sz;i++){
                int temp = q.front();
                q.pop();
                if(vis.count(temp)) continue;
                vis.insert(temp);
                for(auto ng:adj[temp]){
                    if(!vis.count(ng))q.push(ng);
                }
            }
        }
        return c-1;
    }
};