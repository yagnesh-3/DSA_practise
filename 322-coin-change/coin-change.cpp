class Solution {
public:
    int f(vector<int>& coins, int amount,vector<vector<int>>&dp,int i){
        if(i==0){
            if(amount%coins[0] == 0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int nottake = 0+f(coins,amount,dp,i-1);
        int take = INT_MAX;
        if(amount >= coins[i] ){
            take = 1+f(coins,amount-coins[i],dp,i);
        }
        return dp[i][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int  n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans =  f(coins,amount,dp,n-1);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};