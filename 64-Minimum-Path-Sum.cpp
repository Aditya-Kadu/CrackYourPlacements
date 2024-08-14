class Solution {
public:

    int makeit(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(i<0 || j<0){
            return 1e7;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left=grid[i][j]+makeit(i-1,j,grid,dp);
        int up=grid[i][j]+makeit(i,j-1,grid,dp);
        return dp[i][j]=min(left,up);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans=makeit(n-1,m-1,grid, dp);
        return ans;
    }
};