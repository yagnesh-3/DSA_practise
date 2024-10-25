class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        
        for (const string& dir : folder) {
            // If ans is empty or the current directory is not a prefix of the last added directory in ans
            if (ans.empty() || dir.substr(0, ans.back().length() + 1) != ans.back() + "/") {
                ans.push_back(dir);
            }
        }
        
        return ans;
    }
};
