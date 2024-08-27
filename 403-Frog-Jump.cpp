class Solution {
public:
    bool makeit(vector<int>& stones, int ind, int jmp, vector<vector<int>>& dp) {
        if(ind>=stones.size()) return false;
        if (ind == stones.size() - 1) return true;
        
        if (dp[ind][jmp] != -1) return dp[ind][jmp];

        for (int j = ind + 1; j < stones.size(); j++) {
            int gap = stones[j] - stones[ind];
            if (gap == jmp || gap == jmp + 1 || gap == jmp - 1) {
                if (makeit(stones, j, gap, dp)) {
                    return dp[ind][jmp] = true;
                }
            }
        }

        return dp[ind][jmp] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return makeit(stones, 0, 0, dp); 
    }
};
