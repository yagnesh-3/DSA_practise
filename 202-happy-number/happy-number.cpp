class Solution {
public:
    bool helper(int n,unordered_set<int>&seen) {
        if(n==1) return true;
        if(seen.find(n)!=seen.end()){
            return false;
        }
        seen.insert(n);
        int sum =0;
        while(n!=0){
            int digit = n%10;
            sum = sum+digit*digit;
            n = n/10;
        }
        return helper(sum,seen);
    }
    bool isHappy(int n) {
        unordered_set<int>seen;
        return helper(n,seen);
    }
};