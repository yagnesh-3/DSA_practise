class Solution {
public:
    int f(vector<int>& nums, int target,vector<vector<int>>&dp,int i){
        if(i == 0){
            if(target == 0 && nums[0] ==0) return 2;
            if(nums[0] == target || target == 0) return 1;
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];

        int notake = f(nums,target,dp,i-1);
        int take = 0;
        if(target >= nums[i]){
            take = f(nums,target-nums[i],dp,i-1);
        }
        return dp[i][target] = (notake+take);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totsum = accumulate(nums.begin(),nums.end(),0);
        if(totsum - target <0) return 0;
        if((totsum-target) %2!=0) return 0;
        int s2 = (totsum-target)/2;
        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        return f(nums,s2,dp,n-1);
    }
};