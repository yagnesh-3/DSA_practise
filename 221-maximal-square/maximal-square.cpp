class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int side = 0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(matrix[i][j] == '1' ){
                if (i == 0 || j ==0) dp[i][j] = 1;
            else dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1] , dp[i][j-1] ))+1;
            }
            side = max(side,dp[i][j]);

        }
        }
        return side*side;
    }
};