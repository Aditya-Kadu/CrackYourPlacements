class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            int cnt=0;
            for(auto x: nums){
                if(x<=mid){
                    cnt++;
                }
            }
            if(cnt<=mid){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
    }
};