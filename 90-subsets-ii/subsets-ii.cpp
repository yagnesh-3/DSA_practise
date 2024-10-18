class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> sub;
        sort(nums.begin(),nums.end());
        solve(nums,s,0,sub);
        vector<vector<int>> ans;
        for(auto i : s){
            ans.push_back(i);
        }
        return ans;
    }

    void solve(vector<int>& nums,set<vector<int>>& s,int i,vector<int>& sub){
        if(i==nums.size()){
            s.insert(sub);
            return;
        }
        //take
        sub.push_back(nums[i]);
        solve(nums,s,i+1,sub);
        //not take
        sub.pop_back();
        solve(nums,s,i+1,sub);

    }
};