class Solution {
public:
    int f(vector<int>& coins, int amount, vector<vector<int>>dp,int i){
        if(i==0){
            if(amount%coins[0] == 0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int nottake = 0+f(coins,amount,dp,i-1);
        int take = INT_MAX;
        if(coins[i] <= amount){
            take = 1+f(coins,amount-coins[i],dp,i);
        }
        return dp[i][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins,int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // int ans = f(coins,amount,dp,n-1);
        // ans = (ans>=1e9)?-1:ans;
        // return ans;
        for(int i = 0;i<=amount;i++){
            if(i%coins[0] == 0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }

        for(int i = 1;i<n;i++){
            for(int j = 0;j<=amount;j++){
                int notake = dp[i-1][j];
                int take = INT_MAX;
                if(coins[i] <= j) {
                    take = 1+dp[i][j-coins[i]];
                }
                dp[i][j] = min(take,notake);
            }
        }
        dp[n-1][amount ] = (dp[n-1][amount] >= 1e9)?-1:dp[n-1][amount];
        return dp[n-1][amount];
    }
};