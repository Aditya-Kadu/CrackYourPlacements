class Solution {
public:
    int makeit(int ind1, int ind2, vector<vector<int>>& dp){
        if(ind1==0 && ind2==0){
            return 1;
        }
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int up=makeit(ind1-1,ind2,dp);
        int left=makeit(ind1,ind2-1,dp);
        return dp[ind1][ind2]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return makeit(m-1,n-1,dp);
    }
};