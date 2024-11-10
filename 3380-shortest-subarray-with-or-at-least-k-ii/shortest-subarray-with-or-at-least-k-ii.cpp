class Solution {
public:
    void updateFreq(vector<int>&bitFreq,int number,int val){
        for(int i = 0;i<32;i++){
            if(number&(1<<i))
                bitFreq[i]+=val;
        }
    }

    int getNumber(vector<int>&bitFreq){
        int number = 0;
        long long pow =1;
        for(int i = 0;i<32;i++){
            if(bitFreq[i] > 0){
                number+=pow;
            }
            pow*=2;
        }
        return number;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k==0) return 1;

        int n = nums.size();
        int shortest = INT_MAX;
        int left,right = 0;
        int currOr = 0;
        vector<int>bitFreq(32);
        while(right<n){
            updateFreq(bitFreq,nums[right],1);
            currOr|=nums[right];

            while(left<=right && currOr >=k){
                shortest = min(shortest,right-left+1);
                updateFreq(bitFreq,nums[left],-1);
                currOr = getNumber(bitFreq);
                left++;
            }
            right++;
        }
        return shortest == INT_MAX?-1:shortest;
    }
};