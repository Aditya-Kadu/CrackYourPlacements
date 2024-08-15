class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int,vector<int>> mp;
        for(int i=0;i<manager.size();i++){
            mp[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        vector<int> vis(n,0);
        q.push({headID, informTime[headID]});
        vis[headID]=1;
        int ans=0;
        while(!q.empty()){
            int z=q.front().first;
            int time=q.front().second;
            q.pop();
            ans=max(ans, time);
            cout<<informTime[z];
            for(auto x: mp[z]){
                if(!vis[x]){
                    q.push({x,time+informTime[x]});
                }
            }
        }
        return ans;
    }
};