class Solution {
public:
    void dfs(int x, map<int,int>& vis, map<int,vector<int>> &m,vector<int> &ans){
        vis[x]=1;
        ans.push_back(x);
        for(auto z: m[x]){
            if(vis[z]==0){
                dfs(z,vis,m,ans);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,int> mp;
        for(auto x: adjacentPairs){
            mp[x[0]]++;
            mp[x[1]]++;
        }
        int s = -1;
        for(auto x: mp){
            if(x.second==1){
                s=x.first;
                break;
            }
        }
        map<int,vector<int>> m;
        for(auto x: adjacentPairs){
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }
        vector<int> ans;
        map<int,int> vis;
        for(auto x: mp){
            vis[x.first]=0;
        }
        dfs(s,vis,m,ans);
        return ans;
    }
};