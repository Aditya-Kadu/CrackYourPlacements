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
    vector<string> ans;
    void tra(TreeNode* root, string str){
        if(!root) return;

        if(root->left || root->right) str+=(to_string(root->val)+\->\);
        else{
            str+=(to_string(root->val));
            ans.push_back(str);
        }

        tra(root->left, str);
        tra(root->right,str);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string str=\\;
        tra(root,str);
        return ans;
    }
};