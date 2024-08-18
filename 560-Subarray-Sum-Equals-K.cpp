class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pre(nums.size());
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
        }
        unordered_map<int,int> mp;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(pre[i]==k){
                cnt++;
            }
            if(mp.find(pre[i]-k)!=mp.end()){
                cnt+=mp[pre[i]-k];
            }
            mp[pre[i]]++;
        }
        return cnt;

    }
};