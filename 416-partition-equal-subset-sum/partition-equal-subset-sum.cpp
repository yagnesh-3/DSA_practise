class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total%2!=0) return false;

        int target = total/2;
        vector<bool>ar(target+1,false);
        ar[0] = true;
        for(int num:nums){
            for(int j = target;j>=num;j--){
                ar[j] = ar[j] || ar[j-num];
            }
        }
        return ar[target];
    }
};