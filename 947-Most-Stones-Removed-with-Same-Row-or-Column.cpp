class Solution {
public:
    int dfs(vector<vector<int>>& stones, vector<int>& vis, int ind, int& n){
        vis[ind]=1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i] && (stones[i][0]==stones[ind][0] || stones[ind][1]==stones[i][1])){
                ans+=(dfs(stones,vis,i,n)+1);
            }

        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> vis(n,0);
        int res=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                res+=dfs(stones,vis,i,n);
            }
        }
        return res;
    }
};