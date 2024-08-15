class Solution {
public:
    void makeit(vector<vector<int>> vis, vector<vector<int>>& image, int sr, int sc, int color, int ogcolor){
        vis[sr][sc]=1;
        image[sr][sc]=color;
        int k[]={-1,0,+1,0};
        int l[]={0,-1,0,+1};
        for(int i=0;i<4;i++){
            int nr = sr+k[i];
            int nc = sc+l[i];
            if(nr>=0 && nr<image.size() && nc>=0 && nc<image[0].size() && vis[nr][nc]==0 && image[nr][nc]==ogcolor){
                makeit(vis, image, nr, nc, color, ogcolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> vis(image.size(),vector<int> (image[0].size(),0));
        int ogcolor= image[sr][sc];
        makeit(vis, image, sr, sc, color, ogcolor);
        return image;
    }
};