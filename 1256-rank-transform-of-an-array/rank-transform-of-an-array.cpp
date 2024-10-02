class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sarr = arr;
        vector<int>ans;
        map<int,int>mp;
        sort(sarr.begin(),sarr.end());
        int rank = 1;
        for(int i = 0;i<arr.size();i++){
            if(mp.find(sarr[i])==mp.end() ){
                mp.insert({sarr[i],rank++});
            }
        }
        for(const auto &i : mp){
            cout<<i.first<<"-"<<i.second<<endl;
        }
        for(auto i : arr){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};