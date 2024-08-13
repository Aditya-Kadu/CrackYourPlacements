class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxi=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            int pro = prices[i]-mini;
            maxi=max(maxi,pro);
            mini=min(mini,prices[i]);
        }
        return maxi;
    }
};