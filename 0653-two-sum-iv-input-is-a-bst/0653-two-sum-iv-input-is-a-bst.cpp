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
    void dfs(TreeNode* root,unordered_set<int> &st,int k,int &c){
        if(!root) return;
        int a = root->val;
        if(st.count(k-a)){
            c++;
            return;
        }
        st.insert(root->val);
        dfs(root->left,st,k,c);
        dfs(root->right,st,k,c);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        int c = 0;
        dfs(root,st,k,c);
        if(c>0) return true;
        else return false;
    }
};