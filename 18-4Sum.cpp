class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector <vector <int>> ans;
        set <vector <int>> s;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int k=j+1;
                int m=n-1;
                while(k<m){
                    long long sum=0;
                    sum+=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[m];
                    if(sum==target){
                        s.insert({nums[i],nums[j],nums[k],nums[m]});
                        k++;
                        m--;
                    }
                    else if (sum<target){
                        k++;
                    }
                    else{
                        m--;
                    }
                }
            }

            
        }
        for(auto x: s){
            ans.push_back(x);
        }
        return ans;
    }
};