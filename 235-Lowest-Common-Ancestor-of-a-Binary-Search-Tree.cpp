/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void traverse(TreeNode* root, TreeNode* p, TreeNode* q, 
    vector<TreeNode*>& vec, vector<vector<TreeNode*>>& ans){
        if(root==NULL){
            return;
        }
        vec.push_back(root);
        if(root==p || root==q){
            ans.push_back(vec);
        }
        
        traverse(root->left, p, q, vec, ans);
        traverse(root->right, p, q, vec, ans);
        vec.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<vector<TreeNode*>> ans;
        vector<TreeNode*> vec;
        if(root==NULL){
            return NULL;
        }
        traverse(root, p, q, vec, ans);
        TreeNode* lca=root;
        int l = min(ans[0].size(), ans[1].size());
        for(int i=0;i<l;i++){
            if(ans[0][i]==ans[1][i]){
                lca= ans[0][i];
            }
            else{
                break;
            }
        }
        return lca;
    }
};