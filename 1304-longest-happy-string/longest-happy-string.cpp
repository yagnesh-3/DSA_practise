class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        string s  = "";
        while(a>0||b>0||c>0){
            int n = s.length();
            if(n>=2 && s[n-1] == s[n-2]){
                
                if(s[n-1] == 'a'){
                    if(b>=c && b>0){
                        s+="b";
                        b--;
                    }else if(c>0){
                        s+="c";
                        c--;
                    }else{
                        break;
                    }
                }

                
                else if(s[n-1] == 'b'){
                    if(a>=c && a>0){
                        s+="a";
                        a--;
                    }else if(c>0){
                        s+="c";
                        c--;
                    }else{
                        break;
                    }
                }

                
               else if(s[n-1] == 'c'){
                    if(a>=b && a>0){
                        s+="a";
                        a--;
                    }else if(b>0){
                        s+="b";
                        b--;
                    }else{
                        break;
                    }
                }


            }else{
                if(a>=b && a>=c && a>0){
                    s+="a";
                    a--;
                }else if(b>=c && b>0){
                    s+="b";
                    b--;
                }else if(c>0){
                    s+="c";
                    c--;
                }
            }
        }
        return s;
    }
};