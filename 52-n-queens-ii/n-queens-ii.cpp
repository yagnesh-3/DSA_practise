
class Solution {
public:
    vector<vector<string>>ans;
    bool isValid(int i , int j ,vector<string>&board,int n){
        for(int row = 0;row<i;row++){
            if(board[row][j] == 'Q') return false;  
            if(board[i][row] == 'Q') return false;  
        }
        int ti = i;
        int tj = j;
        while(ti>=0 && tj>=0){
            if(board[ti][tj] == 'Q') return false;
            ti--;
            tj--;
        }
        ti = i;
        tj = j;
        while(ti>=0 && tj<n){
            if(board[ti][tj] == 'Q') return false;
            ti--;
            tj++;
        }
    
        return true;
    }
    void solve(int row,vector<string>&board,int n){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int i = 0;i<n;i++){
            if(isValid(row,i,board,n)){
                board[row][i] ='Q';
                solve(row+1,board,n);
                board[row][i] ='.';
            }
        }
    }
    int totalNQueens(int n){
        vector<string>board;
        string s(n,'.');
        for(int i = 0;i<n;i++){
           board.push_back(s);
        }
        solve(0,board,n);
        return ans.size();
    }
};