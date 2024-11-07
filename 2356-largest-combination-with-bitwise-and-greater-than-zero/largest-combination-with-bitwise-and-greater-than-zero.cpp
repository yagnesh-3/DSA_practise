class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxFreq = 0;
        for(int i = 0;i<32;i++){
            int freq = 0;
            for(int j : candidates){
                if(j & (1<<i)) freq++;
            }
            maxFreq = max(freq,maxFreq);
        }
        return maxFreq;
    }
};