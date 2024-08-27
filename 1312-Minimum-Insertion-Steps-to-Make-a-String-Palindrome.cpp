class Solution {
public:
    int makeit(int i,int j,string &a,string &b,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j])
            return dp[i][j]=1+makeit(i-1,j-1,a,b,dp);
        else
            return dp[i][j]=max(makeit(i-1,j,a,b,dp),makeit(i,j-1,a,b,dp)); 
        
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        string t=s;
        reverse(t.begin(),t.end());
        return n-makeit(n-1,n-1,s,t,dp);
    }
};