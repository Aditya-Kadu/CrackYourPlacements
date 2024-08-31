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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<vector<int>> ans0;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        // int cnt=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> vec;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                vec.push_back(node->val);
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
                
            }
            ans.push_back(vec);
        }

        queue<TreeNode*> qe;
        qe.push(root);
        // int cnt=0;
        while(!qe.empty()){
            int n=qe.size();
            vector<int> vec;
            for(int i=0;i<n;i++){
                TreeNode* node=qe.front();
                qe.pop();
                vec.push_back(node->val);
                if(node->left) qe.push(node->left);
                if(node->right) qe.push(node->right);
                
                
            }
            ans0.push_back(vec);
        }
        vector<vector<int>> fin;
        for(int i=0;i<ans.size();i++){
            if(i%2!=0){
                fin.push_back(ans[i]);
            }
            else{
                fin.push_back(ans0[i]);
            }
        }
        return fin;
    }
};