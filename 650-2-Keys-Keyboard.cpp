class Solution {
public:
    int makeit(int ind, int prev, int n){
        if(ind==n){
            return 0;
        }

        if(ind>n){
            return INT_MAX/2;
        }

        int st1 = 2+makeit(2*ind,ind,n);
        int st2 = 1+makeit(ind + prev, prev,n);
        return min(st1,st2);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        return 1+makeit(1,1,n);
    }
};