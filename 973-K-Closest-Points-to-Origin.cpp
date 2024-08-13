class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> ans;
        for(auto x: points){
            int a=x[0];
            int b=x[1];
            int dist = a*a+b*b;
            pq.push({dist,{a,b}});
        }
        while(k!=0){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
            k--;
        }
        return ans;
    }
};