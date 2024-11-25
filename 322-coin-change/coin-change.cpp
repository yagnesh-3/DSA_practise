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
        // int ans =  f(coins,amount,dp,n-1);
        // if(ans >= 1e9) return -1;
        // else return ans;
        for(int i = 0;i<=amount;i++){
            if(i%coins[0] == 0){
                dp[0][i] = i/coins[0];
            }else{
                dp[0][i] = 1e9;
            }
        }
        for(int i = 1;i<n;i++){
            for(int target = 0;target <= amount;target++){
                int notake= dp[i-1][target];
                int take = INT_MAX;
                if(target>= coins[i]){
                    take = 1+dp[i][target-coins[i]];
                }

                dp[i][target] = min(take,notake);
            }
        }

       if(dp[n-1][amount] >= 1e9) return -1;
       else return dp[n-1][amount];
    }
};