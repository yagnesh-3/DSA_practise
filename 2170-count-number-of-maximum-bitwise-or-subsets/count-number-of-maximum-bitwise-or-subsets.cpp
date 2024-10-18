
class Solution {
public:
    int ans = 0;
    void helper(int i,vector<int>v,vector<int>arr,int target,int tor){
        if(i == arr.size()){
            if(tor == target)
            ans++;
            return;
        }
        helper(i+1,v,arr,target,tor);
        v.push_back(arr[i]);
        helper(i+1,v,arr,target,tor|arr[i]);
    }
    int countMaxOrSubsets(vector<int>& nums) {
         ios::sync_with_stdio(0);         cin.tie(0);
        int arrOr = 0;
        for(int i:nums) arrOr = arrOr|i;
        vector<int>v;
        helper(0,v,nums,arrOr,0);
        return ans;
    }
};