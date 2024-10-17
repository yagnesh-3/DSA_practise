class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.length();
        int m = t2.length();
        int arr[n+1][m+1] ;
        for(int i=0;i<=n;i++ ){
            for(int j = 0;j<=m;j++){
                if(i==0 || j==0){
                    arr[i][j] = 0;
                }
                else if(t1[i-1] == t2[j-1]){
                    arr[i][j] = 1+arr[i-1][j-1];
                }
                else{
                    arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
        return arr[n][m];
    }
};