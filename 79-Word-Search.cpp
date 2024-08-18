class Solution {
public:
    bool makeit(int i, int j, int ind, vector<vector<int>>& vis,vector<vector<char>>& board, string& word){
        if(ind==word.size()) return true;

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[ind] || vis[i][j]==1) return false;

        vis[i][j]=1;

        if(makeit(i+1,j,ind+1,vis,board,word) || makeit(i-1,j,ind+1,vis,board,word) || makeit(i,j+1,ind+1,vis,board,word) || makeit(i,j-1,ind+1,vis,board,word)) return true;

        vis[i][j]=0;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(makeit(i,j,0,vis,board,word)) return true;
            }
        }
        return false;
    }
};