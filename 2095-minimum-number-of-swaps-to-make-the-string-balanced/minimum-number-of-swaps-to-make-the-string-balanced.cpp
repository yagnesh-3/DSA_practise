class Solution {
public:
    int minSwaps(string s) {
        int ans =0;
        for(char c :s){
            if(c=='['){
                ans+=1;
            }else if(ans>0){
                ans-=1;
            }
        }
        return (ans+1)/2;
    }
};