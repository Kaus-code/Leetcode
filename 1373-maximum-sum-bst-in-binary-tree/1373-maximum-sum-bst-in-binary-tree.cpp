struct Info {
    bool isBST;
    int minVal, maxVal, sum;
};

class Solution {
    int maxSum = 0;

public:
    Info solve(TreeNode* root) {
        // Base case: An empty tree is a BST with sum 0
        if (!root) return {true, INT_MAX, INT_MIN, 0};

        // 1. Get info from children (Bottom-Up)
        Info left = solve(root->left);
        Info right = solve(root->right);
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {   
            int currentSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currentSum);
            return {
                true, 
                min(root->val, left.minVal), // New minimum for this subtree
                max(root->val, right.maxVal), // New maximum for this subtree
                currentSum
            };
        }
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        solve(root);
        return maxSum;
    }
};