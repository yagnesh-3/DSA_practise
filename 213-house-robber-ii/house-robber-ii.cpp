class Solution {
public:
    int f(vector<int>&nums){
        int n = nums.size();
        int prev = nums[0];
        int prev2 =0;
        for(int i = 1;i<n;i++){
            int take = (i>1)?nums[i]+prev2:nums[i];
            int nottake = 0+prev;
            int cur = max(take,nottake);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i =0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]); 
            if(i!=n-1) temp2.push_back(nums[i]); 
        }
        int t1 = f(temp1);
        int t2 = f(temp2);

        return max(t1,t2);
    }
};