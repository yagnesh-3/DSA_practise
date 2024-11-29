class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            x = 1/x;
        }
        return solve(x,n);
        // return pow(x,n);
    }
    double solve(double x,int n){
        if(n == 0)return 1;
        if(n==1)return x;
        //even
        double currn = solve(x,n/2);
        if(n%2 == 0){
            return currn*currn;
        }
        else{
            return currn*currn*x;
        }

    }
};