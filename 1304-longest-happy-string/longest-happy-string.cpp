class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        
        while (a > 0 || b > 0 || c > 0) {
            int n = s.size();
            
            // Check if the last two characters are the same
            if (n >= 2 && s[n - 1] == s[n - 2]) {
                if (s[n - 1] == 'a') {
                    // 'a' was used twice, now pick 'b' or 'c'
                    if (b >= c && b > 0) {
                        s += 'b';
                        b--;
                    } else if (c > 0) {
                        s += 'c';
                        c--;
                    } else {
                        break; // No valid character left to use
                    }
                } else if (s[n - 1] == 'b') {
                    // 'b' was used twice, now pick 'a' or 'c'
                    if (a >= c && a > 0) {
                        s += 'a';
                        a--;
                    } else if (c > 0) {
                        s += 'c';
                        c--;
                    } else {
                        break;
                    }
                } else if (s[n - 1] == 'c') {
                    // 'c' was used twice, now pick 'a' or 'b'
                    if (a >= b && a > 0) {
                        s += 'a';
                        a--;
                    } else if (b > 0) {
                        s += 'b';
                        b--;
                    } else {
                        break;
                    }
                }
            } else {
                // No two consecutive characters are the same, pick the largest available character
                if (a >= b && a >= c && a > 0) {
                    s += 'a';
                    a--;
                } else if (b >= a && b >= c && b > 0) {
                    s += 'b';
                    b--;
                } else if (c >= a && c >= b && c > 0) {
                    s += 'c';
                    c--;
                }
            }
        }
        
        return s;
    }
};
