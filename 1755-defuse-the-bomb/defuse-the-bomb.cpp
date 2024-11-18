class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans;
        if(k==0){ 
            for(int i: code) ans.push_back(0); 
        } 
        if(k>0){
            for(int i =0;i<n;i++){
                int sum = 0;
                for(int j = 1;j<=k;j++){
                    int newIdx = (i+j)%n;
                    sum+=code[newIdx];
                }
                ans.push_back(sum);
            }
        }else if(k<0){
            for(int i =0;i<n;i++){
                int sum = 0;
                for(int j = k*-1;j>0;j--){
                    int newIdx = (n-j+i)%n;
                    cout<<code[newIdx]<<" ";
                    sum+=code[newIdx];
                }
                ans.push_back(sum);
                cout<<endl;
            }
        }
        return ans;
    }
};