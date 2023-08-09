class Solution {
public:
        
    void solve(int col,vector<vector<string>>& ans, vector<string>& board, int n, vector<int>& left, vector<int>& lowerDiag, vector<int>& upperDiag){
        if(n==col){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(left[row]==0 && upperDiag[n-1-row+col]==0 && lowerDiag[row+col]==0){
                board[row][col]='Q';
                left[row]=1;upperDiag[n-1-row+col]=1;lowerDiag[row+col]=1;
                solve(col+1,ans,board,n,left,lowerDiag,upperDiag);
                board[row][col]='.';
                left[row]=0;upperDiag[n-1-row+col]=0;lowerDiag[row+col]=0;
            }
        
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector < vector < string >> ans;
        vector < string > board(n);
        vector<int> left(n,0), lowerDiag(2*n-1,0), upperDiag(2*n-1,0);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        
        solve(0,ans,board,n,left, lowerDiag, upperDiag);
        return ans;
    }
};