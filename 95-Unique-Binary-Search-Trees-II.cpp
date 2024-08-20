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
    
    vector<TreeNode*> makeit(int st,int en){
        vector<TreeNode*> ans;
        if(st>en){
            ans.push_back(NULL);
            return ans;
        }

        for(int i=st;i<=en;i++){
            vector<TreeNode*> ls = makeit(st,i-1);
            vector<TreeNode*> rs = makeit(i+1,en);

            for(auto l: ls){
                for(auto r: rs){
                    TreeNode* root = new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return makeit(1,n);
    }
};