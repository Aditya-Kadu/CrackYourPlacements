class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0;
        priority_queue<double> pq;
        for(auto x: nums){
            pq.push(x);
            sum+=x;
        }
        double temp=sum/2;
        double red = 0;
        int cnt=0;
        while(red<temp){
            double a=pq.top();
            double b=a/2;
            pq.pop();
            red+=(a-b);
            pq.push(b);
            cnt++;
        }
        return cnt;
    }
};