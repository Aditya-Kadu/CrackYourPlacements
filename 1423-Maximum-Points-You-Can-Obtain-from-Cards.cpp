class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // deque<int> q(k);
        int n=cardPoints.size();
        int sum=0;
        for(auto x: cardPoints){
            sum+=x;
        }
        int var=0;
        for(int i=0;i<n-k;i++){
            // q.push(cardPoints[i]);
            var+=cardPoints[i];
        }
        int maxi=INT_MIN;
        maxi=max(maxi,sum-var);
        
        for(int i=n-k;i<n;i++){
            var+=cardPoints[i];
            var-=cardPoints[i+k-n];
            maxi=max(maxi,sum-var);
        }
        return maxi;
    }
};