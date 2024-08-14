class Solution {
public:
    int climbStairs(int n) {
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        vector<int> ans(n+1);
        ans[0]=ans[1]=1;
        for(int i=2;i<=n;i++){
            ans[i]=ans[i-1]+ans[i-2];
        }
        return ans[n];
    }
};