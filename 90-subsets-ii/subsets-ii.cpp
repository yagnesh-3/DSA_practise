class Solution {
public:
    void helper(int i,vector<int>&v,vector<int>&arr,set<vector<int>>&ans){
        if(i==arr.size()){
            ans.insert(v);
            return;
        }
        v.push_back(arr[i]);
        helper(i+1,v,arr,ans);
        v.pop_back();
        helper(i+1,v,arr,ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>v;
        sort(nums.begin(),nums.end());
        helper(0,v,nums,ans);
        vector<vector<int>>fans;
        for(auto i : ans){
            fans.push_back(i);
        }
        
        return fans;
    }
};