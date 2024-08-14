class Solution {
public:
    int makeit(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = makeit(i + 1, j, matrix,dp);
        int right = makeit(i, j + 1, matrix,dp);
        int diag = makeit(i + 1, j + 1, matrix,dp);
        int size= 1+min({down, right, diag});
        return dp[i][j]=size;
        
    }
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1){
                    ans+=makeit(i,j,matrix,dp);
                }
            }
        }
        return ans;
    }
};