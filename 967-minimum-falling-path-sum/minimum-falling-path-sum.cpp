class Solution {
public:
    int f(vector<vector<int>>& matrix,int i,int j,int m,vector<vector<int>>& dp){
        int mini = INT_MAX;
        if(j<0 || j>=m) return 1e9;

        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        else{
            int d = matrix[i][j]+f(matrix,i-1,j,m,dp);
            int dl = matrix[i][j]+f(matrix,i-1,j-1,m,dp);
            int dr = matrix[i][j]+f(matrix,i-1,j+1,m,dp);
            mini = min(d,min(dl,dr));
        }
        return dp[i][j] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>>dp(m,vector<int>(m,-1));
        // for(int j = 0;j<m;j++){
        //     int ans = f(matrix,m-1,j,m,dp);
        //     mini = min(mini,ans);
        // }
        // return mini;
        for(int j=0;j<m;j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1;i<m;i++){
           for(int j = 0;j<m;j++){
            int up = matrix[i][j]+dp[i-1][j];
            int ul = (j-1>=0)?matrix[i][j]+dp[i-1][j-1]:matrix[i][j]+1e9;
            int ur = (j+1<m)?matrix[i][j]+dp[i-1][j+1]:matrix[i][j]+1e9;
            dp[i][j] = min(up,min(ul,ur));
           }
        }
        int ans = INT_MAX;
        for(int j = 0;j<m;j++){
            ans = min(ans,dp[m-1][j]);
        }
        return ans;
    }
};