class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>v,vector<int>nums,map<int,bool>used){
        if(v.size() == nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(!used[nums[i]]){
                used[nums[i]] = true;
                v.push_back(nums[i]);
                helper(v,nums,used);
                v.pop_back();
                used[nums[i]] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>v;
        map<int,bool>used;
        for(int i:nums){
            used[i] = false;
        }
       helper(v,nums,used);
       return ans;
    }
};