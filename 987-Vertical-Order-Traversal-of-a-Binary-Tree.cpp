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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
       queue<pair<TreeNode*, pair<int, int>>> q;
       map<int, map<int, multiset<int>>> mp;
       if(root==NULL){
           return ans;
       }
       q.push({root,{0,0}});
       while(!q.empty()){
           int n=q.size();
           
           auto it = q.front();
           TreeNode*temp=it.first;
           int v = it.second.first;
           int h = it.second.second;
           
            mp[v][h].insert(temp->val);
           
           q.pop();
           
           if(temp->left){
               q.push({temp->left,{v-1,h+1}});
           }
           if(temp->right){
               q.push({temp->right,{v+1,h+1}});
           }
        
       }
       for(auto j: mp){
           vector<int> col;
           for(auto x: j.second){
            col.insert(col.end(), x.second.begin(), x.second.end());
           }
           ans.push_back(col);
       }
       return ans;
    }
};