class Solution {
public:

    vector<int>getbin(int n){
        vector<int>ret;
        while(n){
            if(n&1) ret.push_back(1);
            else ret.push_back(0);
            n>>=1;
        }
        return ret;
    }

    long long minEnd(int n, int x) {
        if(n==1) return x;
        
        vector<int>zero_pos;
        int count =0;
        int val = x;
        while(val){
            if((val&1) == 0) zero_pos.push_back(count);
            count++;
            val>>=1;
        }
        int reqd_bits = ceil(log2(n));
        for(int i = zero_pos.size();i<reqd_bits;i++){
            zero_pos.push_back(count++);
        }
        vector<int> append_bits = getbin(n-1);
        long long ans = x;
        int pos = append_bits.size();
        while(pos--){
            if(append_bits.back() == 1){
                ans+=pow(2,zero_pos[pos]) * append_bits[pos];
            }
        }
        return ans;
    }
};