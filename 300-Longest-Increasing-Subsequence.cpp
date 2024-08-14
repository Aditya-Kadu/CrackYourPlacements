class Solution {
public:
    int makeit(vector<int>& nums, int ind, int prev, vector<vector<int>>& dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        
        int take=0;
        if(prev==-1 || nums[prev]<nums[ind]){
            take=1+makeit(nums,ind+1,ind,dp);
        }
        int not_take=makeit(nums,ind+1,prev,dp);
        return dp[ind][prev+1]=max(take,not_take);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        // int maxi=INT_MIN;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        int ans = makeit(nums,0,-1,dp);
        return ans;
    }
};