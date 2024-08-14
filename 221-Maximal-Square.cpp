class Solution {
public:
    int makeit(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& dp){
        if(i>=matrix.size() || j>=matrix[0].size()){
            return 0;
        }
        if(matrix[i][j]=='0'){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int a=min(makeit(matrix,i,j+1,dp),makeit(matrix,i+1,j,dp));
        int b=min(a,makeit(matrix,i+1,j+1,dp));
        return dp[i][j]=1+b;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    ans=max(ans,makeit(matrix,i,j,dp));
                }
            }
        }
        return pow(ans,2);
    }
};