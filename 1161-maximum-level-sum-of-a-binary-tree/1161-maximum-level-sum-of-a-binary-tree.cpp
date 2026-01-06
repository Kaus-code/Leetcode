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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int maxi = root->val;
        int lvl = 1;
        int j = 1;
        q.push(root);
        while(!q.empty()){
            int sum = 0;
            int size = q.size();
            for(int i =0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
            if(maxi<sum) {
                maxi = sum;
                lvl = j;
            }
            j++;
        }
        return lvl;
    }
};