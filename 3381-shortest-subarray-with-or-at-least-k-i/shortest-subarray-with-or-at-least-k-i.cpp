class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int curOr = 0;
           
            for(int j = i;j<n;j++){
                curOr|=nums[j];
                if(curOr>=k) ans = min(ans,j-i+1);
               
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};