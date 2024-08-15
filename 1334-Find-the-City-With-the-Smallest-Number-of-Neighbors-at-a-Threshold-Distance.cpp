class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n,vector<int>(n,1e7));
        for(auto x: edges){
            dp[x[0]][x[1]]=x[2];
            dp[x[1]][x[0]]=x[2];
        }
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                    dp[j][i]=min(dp[j][i],dp[j][k]+dp[k][i]);
                }
            }
        }
        int mini=INT_MAX;
        int ans=-1;
        int ind=0;
        for(auto x: dp){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(x[i]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=mini){
                mini=cnt;
                ans=ind;
            }
            ind++;
        }
        return ans;

    }
};