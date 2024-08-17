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
    int cnt = 0;

    void dfs(TreeNode* node, long long sum) {
        if (!node) return;
        
        sum -= node->val;
        if (sum == 0) cnt++;

        dfs(node->left, sum);
        dfs(node->right, sum);
    }

    void findPaths(TreeNode* node, int targetSum) {
        if (!node) return;

        dfs(node, targetSum);

        findPaths(node->left, targetSum);
        findPaths(node->right, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        findPaths(root, targetSum);
        return cnt;
    }
};