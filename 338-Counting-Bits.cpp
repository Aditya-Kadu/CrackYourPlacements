class Solution {
public:
    int makeit(int i){
        if(i==0){
            return 0;
        }
        return (i%2+makeit(i/2));
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i]=makeit(i);
        }
        return ans;
    }
};