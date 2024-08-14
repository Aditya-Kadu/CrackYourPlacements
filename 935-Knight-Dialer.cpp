class Solution {
public:
    int mod=1e9+7;
    int dfs(int start, vector<vector<int>> &v, int n, vector<vector<int>>& dp){
        if(n==0){
            
            return 1;
        }
        if(dp[start][n]!=0){
            return dp[start][n];
        }
        for(auto x: v[start]){
            dp[start][n]=(dp[start][n]+dfs(x,v,n-1, dp))%mod;  
        }
        return dp[start][n]%mod;
    }
    int knightDialer(int n) {
        vector<vector<int>> v;
        int cnt=0;
        v={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        vector<vector<int>> dp(10, vector<int>(n,0));
        for(int i=0;i<=9;i++){
            // vector<int> vis(10,0);
            cnt=(cnt+dfs(i,v,n-1, dp))%mod;
        }
        return cnt;
    }
};