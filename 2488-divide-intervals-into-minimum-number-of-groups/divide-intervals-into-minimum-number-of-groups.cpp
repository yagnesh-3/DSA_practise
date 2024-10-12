class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>start(intervals.size());
        vector<int>en(intervals.size());
        int groupCount = 0;
       for(int i = 0;i<intervals.size();i++){
        start[i] = intervals[i][0];
        en[i] = intervals[i][1];
       }
       sort(start.begin(),start.end());
       sort(en.begin(),en.end());
        int j = 0;
       for(int i  : start){
        if(i <= en[j]){
            groupCount++;
        }
        else j++;
       }
       return groupCount;
    }
};