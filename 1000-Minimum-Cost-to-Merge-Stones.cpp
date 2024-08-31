class Solution {
public:
    int makeit(vector<int>& stones, int i, int k, int j, vector<int>& pre, vector<vector<int>>& dp){
        if(i+k-1>j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int t = i; t<j;t=t+k-1){
            mini = min(mini,(makeit(stones,i,k,t,pre,dp)+makeit(stones,t+1,k,j,pre,dp)));
        }
        if((j-i)%(k-1)==0){
            mini=mini+pre[j+1]-pre[i];
        }
        return dp[i][j]=mini;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        vector<int> pre(n+1,0);
        
        if((n-1)%(k-1)!=0) return -1;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+stones[i-1];
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return makeit(stones,0,k,n-1,pre,dp);
    }
};