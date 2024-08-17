class Solution {
public:
    vector<int> ans;

    void dfs(int tgt, unordered_map<int,vector<int>>& adj, unordered_map<int, bool>& vis, int k){
        if(k == 0){
            ans.push_back(tgt);
            return;
        }
        vis[tgt] = true;
        for(auto x : adj[tgt]){
            if(!vis[x]){
                dfs(x, adj, vis, k - 1);
            }
        }
    }

    void makegraph(TreeNode* root, unordered_map<int,vector<int>>& adj){
        if(root->left != NULL){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            makegraph(root->left, adj);
        }
        if(root->right != NULL){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            makegraph(root->right, adj);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL) return {};
        
        unordered_map<int,vector<int>> adj;
        makegraph(root, adj);

        unordered_map<int, bool> vis;
        dfs(target->val, adj, vis, k);

        return ans;
    }
};