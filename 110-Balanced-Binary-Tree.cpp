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
    int postorder(TreeNode* root, bool &ans){
        if(root==NULL){
            return 0;
        }
        int l=postorder(root->left, ans);
        int r=postorder(root->right, ans);
        if(abs(l-r)>1){
            ans=false;
        }
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        if(root==NULL){
            return ans;
        }
        postorder(root, ans);
        return ans;
    }
};