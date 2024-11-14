class Solution {
public:
    int f(int index,int jumps,vector<int>& nums, vector<vector<int>>&dp){
        int n = nums.size();
        if(index >= n-1) return jumps;
        if(dp[index][jumps]!=-1 ) return dp[index][jumps];
        int mini = INT_MAX;
        for(int i = 1;i<=nums[index];i++){
            mini = min(mini,f(index+i,jumps+1,nums,dp));
        }

        return dp[index][jumps] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return f(0,0,nums,dp);
        int jumps = 0;
        int l = 0;
        int r = 0;
        while(r<n-1){
            int far = 0;
            for(int i = l;i<=r;i++){
                far = max(far,i+nums[i]);
            }
            l= r+1;
            r =far;
            jumps++;
        }
        return jumps;
    }

};