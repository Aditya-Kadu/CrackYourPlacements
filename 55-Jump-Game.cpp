class Solution {
public:
    bool makeit(int ind, vector<int>& nums, vector<int>& dp){
        if(ind>=nums.size()-1){
            return true;
        }

        if(dp[ind]!=-1) return dp[ind];

        for(int i=nums[ind];i>=1;i--){
            if(makeit(ind+i,nums,dp)) return dp[ind]=true;
        }
        return dp[ind]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return makeit(0,nums,dp);
    }
};