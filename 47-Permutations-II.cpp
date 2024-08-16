class Solution {
public:
    void perm(set<vector<int>>& s, vector<int>& nums, int l, int r){
        if(l==r){
            s.insert(nums);
            return;
        }
        for(int i=l;i<=r;i++){
            swap(nums[i],nums[l]);
            perm(s,nums,l+1,r);
            swap(nums[i],nums[l]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        set<vector<int>> s;
        perm(s,nums,l,r);
        vector<vector<int>> ans;
        for(auto x: s){
            ans.push_back(x);
        }
        return ans;
    }
};