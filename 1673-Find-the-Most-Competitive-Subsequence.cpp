class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            while(v.size()!=0 && v[v.size()-1]>nums[i] && v.size()+nums.size()-i>k){
                v.pop_back();
            }
            v.push_back(nums[i]);
            if(v.size()==k){
                ans=v;
            }
        }
        return ans;
    }
};