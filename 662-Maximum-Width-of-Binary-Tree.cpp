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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        int maxi=INT_MIN;
        while(!q.empty()){
            int n=q.size();
            int f,l;
            // int min=q.front().second;
            for(int i=0;i<n;i++){
                TreeNode* temp= q.front().first;
                int cur = q.front().second;
                // cur-=min;
                q.pop();
                if(i==0){
                    f=cur;
                }
                if(i==n-1){
                    l=cur;
                }
                if(temp->left){
                    q.push({temp->left,(long long)2*cur+1});
                }
                if(temp->right){
                    q.push({temp->right,(long long)2*cur+2});
                }
            }
            maxi = max(maxi, l-f+1);
        }
        return maxi;
    }
};