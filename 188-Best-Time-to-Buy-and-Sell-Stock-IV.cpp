class Solution {
public:
    int makeit(int ind, int tran, int k, vector<int>& prices, vector<vector<int>>& dp){
        if(ind==prices.size() || tran==2*k) return 0;
        if(dp[ind][tran]!=-1) return dp[ind][tran];
        if(tran%2==0){
            return dp[ind][tran]=max(-prices[ind] + makeit(ind+1, tran+1, k, prices,dp),0 + makeit(ind+1, tran, k, prices,dp));
        }
        else{
            return dp[ind][tran]=max(prices[ind] + makeit(ind+1, tran+1, k, prices,dp),0 + makeit(ind+1, tran, k, prices,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2*k+1, -1));
        return makeit(0,0,k,prices,dp);
    }
};