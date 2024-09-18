class Solution {
public:

    bool isok(int row, int col, vector<string>& board, int n){
        int dummyrow=row;
        int dummycol=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=dummyrow;
        col=dummycol;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        row=dummyrow;
        col=dummycol;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;

    }

    void makeit(vector<vector<string>>& ans, vector<string>& board, int col, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isok(row,col,board,n)){
                board[row][col]='Q';
                makeit(ans,board,col+1,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n, '.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        makeit(ans,board,0,n);
        return ans;
    }
};