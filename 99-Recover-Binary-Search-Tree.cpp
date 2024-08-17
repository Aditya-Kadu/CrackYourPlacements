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
    vector<int> v;
    void inorder(TreeNode*  root){
        if(!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    void tra(TreeNode* root, int a, int b){
        if(!root) return;
        if(root->val==a || root->val==b){
            if(root->val==b){
                root->val=a;
            }
            else{
                root->val=b;
            }
        }
        
        tra(root->left,a,b);
        tra(root->right,a,b);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* temp=root;
        inorder(temp);
        vector<int> z=v;
        sort(v.begin(),v.end());
        int a,b;
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<\ \<<z[i]<<endl;
            if(v[i]!=z[i]){
                a=v[i];
                b=z[i];
                break;
            }
        }
        tra(root,a,b);
    }
};