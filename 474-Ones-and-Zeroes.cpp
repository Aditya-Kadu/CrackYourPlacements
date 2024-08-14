class Solution {
public:
    int makeit(int ind, vector<string>& strs, int m, int n, vector<vector<vector<int>>>& dp){
        if(ind<0){
            return 0;
        }
        if(m<0 || n<0){
            return 0;
        }
        if(dp[ind][m][n]!=-1) return dp[ind][m][n];
        int i0 = count(strs[ind].begin(),strs[ind].end(),'0');
        int i1= strs[ind].size()-i0;

        int exc = makeit(ind-1, strs, m, n,dp);
        int inc = 0;
        if(m>=i0 && n>=i1 ){
            inc=1+makeit(ind-1,strs,m-i0,n-i1,dp);
        }
        return dp[ind][m][n]=max(inc,exc);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));

        return makeit(strs.size()-1,strs, m, n, dp);
    }
};