class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int z=nums.size()-1;
        return max(nums[z-2]*nums[z-1]*nums[z], nums[0]*nums[1]*nums[z]);
    }
};