class Solution {
public:
    int f(int amount, vector<int>& coins, vector<vector<int>>&dp,int i){
        if(i==0){
           return (amount%coins[0] == 0);
        }
        if(dp[i][amount]!=-1) return dp[i][amount];

        int nottake = f(amount,coins,dp,i-1);
        int take = 0;
        if(amount >= coins[i]){
            take = f(amount-coins[i],coins,dp,i);
        }
        return dp[i][amount]  = take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(amount,coins,dp,n-1);
    }
};