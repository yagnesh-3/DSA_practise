class Solution {
public:
    const int mod = 1e9+7;
    long long pow(long long x,long long n){
        int ans = 1;
        while(n>0){
            if(n%2!=0){
                ans =(ans*x)%mod;
                n--;
            }else{
                x =(x*x)%mod;
                n = n/2;
            }
        }
        return ans%mod;
    }
    int countGoodNumbers(long long n) {
    long long even = (n+1)/2;
    long long odd = n/2;        
       
        long long ans = (pow(5,even)*pow(4,odd))%mod;
        return (int)ans%mod;
    }
};