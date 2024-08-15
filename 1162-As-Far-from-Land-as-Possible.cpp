class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        if(q.empty() || q.size()==n*n) return -1;
        int ans=0;
        while(!q.empty()){
            int dis=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            if(x-1>=0 && vis[x-1][y]!=1){
                ans=max(ans,dis+1);
                q.push({dis+1,{x-1,y}});
                vis[x-1][y]=1;
            }
            if(x+1<n && vis[x+1][y]!=1){
                ans=max(ans,dis+1);
                q.push({dis+1,{x+1,y}});
                vis[x+1][y]=1;
            }
            if(y-1>=0 && vis[x][y-1]!=1){
                ans=max(ans,dis+1);
                q.push({dis+1,{x,y-1}});
                vis[x][y-1]=1;
            }
            if(y+1<n && vis[x][y+1]!=1){
                ans=max(ans,dis+1);
                q.push({dis+1,{x,y+1}});
                vis[x][y+1]=1;
            }
            
            
        }
        return ans;
    }
};