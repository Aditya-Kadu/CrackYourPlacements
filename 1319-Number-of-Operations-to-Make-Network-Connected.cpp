class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis){
        vis[i]=1;
        for(auto x:adj[i] ){
            if(!vis[x]){
                dfs(x,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>> adj(n);
        for(auto x: connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int cnt=0;
        vector<int> vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);

            }
        }
        return cnt-1;
    }
};