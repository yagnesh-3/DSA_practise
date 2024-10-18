class Solution {
public:
    set<vector<int>>ans;
    void helper(int i,vector<int>v,vector<int>&arr){
        if(i==arr.size()){
            ans.insert(v);
            return;
        }
        v.push_back(arr[i]);
        helper(i+1,v,arr);
        v.pop_back();
        helper(i+1,v,arr);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>v;
        sort(nums.begin(),nums.end());
        helper(0,v,nums);
        vector<vector<int>>fans;
        for(auto i : ans){
            fans.push_back(i);
        }
        
        return fans;
    }
};