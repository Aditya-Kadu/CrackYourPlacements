class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int maxi = INT_MIN;
        deque<pair<int, int>> dq; 

        for (int i = 0; i < n; i++) {
           
            while (!dq.empty() && points[i][0] - dq.front().second > k) {
                dq.pop_front();
            }

            
            if (!dq.empty()) {
                maxi = max(maxi, points[i][1] + points[i][0] + dq.front().first);
            }

            
            while (!dq.empty() && dq.back().first <= points[i][1] - points[i][0]) {
                dq.pop_back();
            }

           
            dq.push_back({points[i][1] - points[i][0], points[i][0]});
        }

        return maxi;
    }
};