class NumArray {
public:
    vector<int> nums;
    vector<int> pre;
    NumArray(vector<int>& nums) {
        this->nums=nums;
        pre.resize(nums.size());
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
        }
    }
    
    void update(int index, int val) {
        int temp=nums[index];
        nums[index]=val;
        int diff=val-temp;
        for(int i=index;i<nums.size();i++){
            pre[i]+=diff;
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return pre[right];
        
        return pre[right]-pre[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */