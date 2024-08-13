class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<vector<int>> v;
        int cnt=0;
        for(auto i: nums){
            v.push_back({i,cnt});
            cnt++;
        }
        sort(v.begin(),v.end());
        int i=0;
        int j=v.size()-1;
        while(i<j){
            int sum=v[i][0]+v[j][0];
            if(sum<target){
                i++;
            }
            else if(sum>target){
                j--;
            }
            else{
                ans.push_back(v[i][1]);
                ans.push_back(v[j][1]);
                break;
            }
        }
        return ans;
    }
};