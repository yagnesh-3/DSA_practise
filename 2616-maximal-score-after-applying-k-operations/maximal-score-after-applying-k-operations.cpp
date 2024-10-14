class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> maxHeap;
        for(int i :nums){
            maxHeap.push(i);
        }
        for(int i = 0;i<k;i++){
            int maxi = maxHeap.top();
            ans +=maxi;
            maxHeap.pop();
            maxHeap.push(ceil(maxi/3.0));
        }
        return ans;
    }
};