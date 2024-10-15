class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int k =s.length();
        int count = 0;
        for(int i = k-1;i>=0;i--){
           if(s[i] == '0'){
            count++;
           }
           else if(s[i] =='1'){
            ans+=count;
           }
        }
        return ans;
    }
};