class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind=1;
        for(int i=1;i<nums.size();i++){
            if(nums[ind-1]!=nums[i]){
                nums[ind]=nums[i];
                ind++;
            }
        }
        return ind;
    }
};