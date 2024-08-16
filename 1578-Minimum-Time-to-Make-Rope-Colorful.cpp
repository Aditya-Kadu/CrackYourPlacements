class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        if(colors.size()==1) return 0;
        
        int cst=0;
        for(int i=1;i<colors.size();i++){
            if(colors[i-1]==colors[i]){
                cst+=min(neededTime[i-1],neededTime[i]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        return cst;
    }
};