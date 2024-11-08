class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int>ans(n);
        int maxi = (1<<m)-1;
        int f = pow(2,m);
        int xo = nums[0];
        for(int i =1;i<n;i++){
            xo ^= nums[i];
        }
        for(int i = 0;i<n;i++){
            ans[i] = xo^maxi;
            xo = xo^nums[n-1-i];
        }

        return ans;
    }
};