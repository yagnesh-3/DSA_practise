class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        int pind = 0;
        int nind = 1;
        for(int i = 0;i<n;i++){
            if(nums[i]>=0){
                ans[pind] = nums[i];
                pind+=2;
            }else{
                ans[nind] = nums[i];
                nind+=2;
            }
        }
        return ans;
    }
};