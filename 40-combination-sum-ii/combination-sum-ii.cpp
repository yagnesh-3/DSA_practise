class Solution {
public:
    vector<vector<int>>ans;

    void helper(int in,vector<int>v,int target,vector<int>arr){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        for(int i = in;i<arr.size();i++){
            if(i>in && arr[i] == arr[i-1]) continue;
            if(arr[i]>target) break;
            v.push_back(arr[i]);
            helper(i+1,v,target-arr[i],arr);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        helper(0,v,target,candidates);
        return ans;
    }
};