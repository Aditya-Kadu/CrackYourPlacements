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
    bool inorder(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        else if(!root || !subRoot || root->val!=subRoot->val) return false;
        if(root->val==subRoot->val){
            return (inorder(root->left,subRoot->left) && inorder(root->right,subRoot->right));
        }
        return true;
    }
    bool tra(TreeNode* root, TreeNode* subRoot){
        if(!root){
            return false;
        }

        if(root->val==subRoot->val){
            if(inorder(root,subRoot)){
                return true;
            }
        }

        return (tra(root->left,subRoot)) || (tra(root->right,subRoot));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return tra(root,subRoot);
    }
};