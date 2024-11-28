class Solution {
    struct cmp{
        bool operator()(const pair<string,int>&a,const pair<string,int> &b){
            if(a.second == b.second) return a.first >b.first;
            else return a.second<b.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      map<string,int>mp;
      for(auto i:words){
        mp[i]++;
      }  

      vector<pair<string,int>> ans(mp.begin(),mp.end());
      priority_queue<pair<string,int>,vector<pair<string,int>>,cmp>pq(ans.begin(),ans.end());
      vector<string>pr;
      while(k--){
        pr.push_back(pq.top().first);
        pq.pop();
      }
      return pr;
    }
};