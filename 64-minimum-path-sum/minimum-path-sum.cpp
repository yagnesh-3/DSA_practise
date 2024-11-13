class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i =0 ;i<m;i++){
            for(int j = 0;j<n;j++){
                int up = 0;
                int down = 0;
                if(i == 0 && j ==0) dp[i][j] = grid[0][0];
                else{
                if(i>0) up = grid[i][j]+dp[i-1][j];
                else up = grid[i][j]+1e9;
                if(j>0) down = grid[i][j]+dp[i][j-1];
                else down = grid[i][j]+1e9;
                dp[i][j] = min(up,down);

                }
            }
        }
        return dp[m-1][n-1];
    }
};