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
    void inorder(TreeNode* root, int k, int & cnt, int& mini){
        if(!root) return;
        inorder(root->left,k, cnt, mini);
        cnt++;
        if(cnt==k){
            mini=root->val;
            return;
        }
        // ans.push_back(root->val);
        inorder(root->right, k, cnt, mini);
    }
    int kthSmallest(TreeNode* root, int k) {
        // vector<int> ans;
        int cnt=0;
        int mini=INT_MIN;
        inorder(root, k, cnt, mini);
        return mini;

    }
};