class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i0=0;
        int i1=0;
        int i2=0;
        for(auto x: nums){
            if(x==0){
                i0+=1;
            }
            else if(x==1){
                i1+=1;
            }
            else{
                i2+=1;
            }
        }
        int cnt=0;
        for(int i=0;i<i0;i++){
            nums[cnt]=0;
            cnt++;
        }
        for(int i=0;i<i1;i++){
            nums[cnt]=1;
            cnt++;
        }
        for(int i=0;i<i2;i++){
            nums[cnt]=2;
            cnt++;
        }
    }
};