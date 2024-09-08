class Solution {
public:
    int bs(int l, int r, vector<int>& nums, int target){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]<nums[r]){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        int rot=l;
        int ans1=bs(0,rot-1,nums,target);
        int ans2=bs(rot,nums.size()-1,nums, target);
        return max(ans1,ans2);
    }
};