class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[] = {0,0,0};
        int s = 0;
        int e = nums.size()-1;
         for (int num : nums) {
            arr[num]++;
        }
        // for(int i:nums){
        //     cout<<i<<endl;
        // }
        int ind = 0;
        for(int i = 0;i<arr[0];i++){
            nums[ind++] = 0;
        }
        for(int i = 0;i<arr[1];i++){
            nums[ind++] = 1;
        }
        for(int i = 0;i<arr[2];i++){
            nums[ind++] = 2;
        }
        for(int i:nums){
            cout<<i<<endl;
        }
        
    }
};