class Solution {
public:

    bool isVectorPresent(const vector<vector<int>>& ans, const vector<int>& v) {
        auto it = find(ans.begin(), ans.end(), v);
        return it != ans.end();
    }

    void create(vector<int>& nums, vector<vector<int>>& ans, vector<int> v, int ind){
        if(ind==nums.size()){
            sort(v.begin(), v.end());
            if(!isVectorPresent(ans, v)){
                ans.push_back(v);
            }
            return;
        }
        create(nums, ans, v, ind+1);
        v.push_back(nums[ind]);
        create(nums, ans, v, ind+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        create(nums, ans, v, 0);
        return ans;
    }
};