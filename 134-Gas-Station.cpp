class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totgas=0,totcst=0,start=0,tank=0;
        for(int i=0;i<n;i++){
            totcst += cost[i];
            totgas += gas[i];
            tank+=gas[i]-cost[i];
            if(tank<0){
                start=i+1;
                tank=0;
            }
        }
        if(totgas<totcst) return -1;
        return start;
    }
};