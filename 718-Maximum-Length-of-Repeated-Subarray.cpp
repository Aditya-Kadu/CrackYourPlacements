class Solution {
public:
    int res=0;
    int makeit(int ind1, int ind2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int ans=0;
        if(nums1[ind1]==nums2[ind2]){
            ans= 1+makeit(ind1-1,ind2-1,nums1,nums2,dp);
            res=max(res,ans);
        }
        makeit(ind1-1,ind2,nums1,nums2,dp);
        makeit(ind1,ind2-1,nums1,nums2,dp);
        return dp[ind1][ind2]=ans;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int> (nums2.size(),-1));
        makeit(nums1.size()-1,nums2.size()-1,nums1,nums2, dp);
        return res;
    }
};