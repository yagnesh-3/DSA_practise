class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(char i : s){
            if(st.empty()) st.push(i);
            else if((i == 'B' && st.top() == 'A') || (i == 'D' && st.top() == 'C')) st.pop();
            else st.push(i);
        }
        return st.size();
    }
};