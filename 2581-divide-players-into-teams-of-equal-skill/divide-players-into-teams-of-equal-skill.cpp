class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0;
        sort(skill.begin(),skill.end());
        int i = 0;
        int j = skill.size()-1;
        long long tsum = skill[i]+skill[j];
        while(i<j){
            if(skill[i] + skill[j] == tsum){
                sum+=skill[i]*skill[j];
                i++;
                j--;
            }else return -1;
        }
        return sum;
    }
};