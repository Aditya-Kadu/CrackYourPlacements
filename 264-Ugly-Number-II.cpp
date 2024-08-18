class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
        int i2=0;
        int i3=0;
        int i5=0;
        for(int i=1;i<n;i++){
            int s2=dp[i2]*2;
            int s3=dp[i3]*3;
            int s5=dp[i5]*5;

            dp[i]=min({s2,s3,s5});

            if(dp[i]==s2) i2++;
            if(dp[i]==s3) i3++;
            if(dp[i]==s5) i5++;
        }
        return dp[n-1];

    }
};