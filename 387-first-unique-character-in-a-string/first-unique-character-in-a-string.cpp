class Solution {
public:

    int firstUniqChar(string s) {
        map<char,int>mp;
        for(char i :s){
            if(mp.contains(i)) mp[i]+=1;
            else mp[i] =1; 
        }
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(mp[s[i]] == 1) return i;
        }

        return -1;

    }
};