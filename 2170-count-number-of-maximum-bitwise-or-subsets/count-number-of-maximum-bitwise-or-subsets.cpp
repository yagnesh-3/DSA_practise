
class Solution {
public:
    int ans = 0;
    void helper(int i,vector<int>&arr,int target,int tor){
        if(i == arr.size()){
            if(tor == target)
            ans++;
            return;
        }
        helper(i+1,arr,target,tor|arr[i]);
        helper(i+1,arr,target,tor);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int arrOr = 0;
        for(int i:nums) arrOr = arrOr|i;
        helper(0,nums,arrOr,0);
        return ans;
    }
};