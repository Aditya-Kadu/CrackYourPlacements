class Solution {
public:
    // int ans = INT_MAX;
    int dfs(int src, int dst, int k, map<int,vector<pair<int,int>>>& mp, vector<vector<int>>& dp){
        if(src==dst){
            return 0;
        }
        if(k<0){
            return INT_MAX;
        }
        if(dp[src][k]!=-1) return dp[src][k];
        int res=INT_MAX;
        for(auto x: mp[src]){
            int a = x.first;
            int b = x.second;
            int c = dfs(a,dst,k-1,mp,dp);
            if(c!=INT_MAX){
                res=min(res,c+b);
            }
            
        }
        return dp[src][k]=res;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int,vector<pair<int,int>>> mp;
        for(auto x: flights){
            mp[x[0]].push_back({x[1],x[2]});
        }
        // vector<int> vis(n,0);
        vector<vector<int>> dp(n, vector<int>(k+1,-1));
        int ans = dfs(src,dst,k,mp,dp);
        if(ans==INT_MAX) return -1;
        return ans;

    }
};