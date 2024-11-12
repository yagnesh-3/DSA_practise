class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int>ans;
        sort(items.begin(),items.end());
        vector<int>price;
        vector<int>maxBeauty;
        int cur_max = 0;
        for(auto i : items){
            cur_max = max(i[1],cur_max);
            price.push_back(i[0]);
            maxBeauty.push_back(cur_max);
        }  
        for(int i : queries){
            int ub = upper_bound(price.begin(),price.end(),i)-price.begin()-1;
            cout<<ub<<endl;
            if(ub>=0)ans.push_back(maxBeauty[ub]);
            else ans.push_back(0);
        }
        return ans;
        
    }
};