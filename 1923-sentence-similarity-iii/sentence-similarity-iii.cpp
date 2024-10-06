class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        string half;
        string full;
        if(s1.length()>s2.length()){
            full = s1;
            half = s2;
        }else{
            half = s1;
            full = s2;
        }
        vector<string>fw = split(full);
        vector<string>hw = split(half);
        if(half.length()==1 && (hw[0] == fw[0] || hw[0] == fw[fw.size() -1] )) return true;   
        int low = 0;
        int high = 0;

        while(low<hw.size() && hw[low] == fw[low]) low++; 
        while(high<hw.size() && hw[hw.size()-high -1] == fw[fw.size()-high -1]) high++; 
        return low+high >= hw.size();



    }
    private:
    // Helper function to split a sentence into words
    vector<string> split(const string &sentence) {
        vector<string> words;
        istringstream iss(sentence);
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    }
};