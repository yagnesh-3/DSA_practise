class Trie{
    public:
    Trie* child[26];
    bool isTerminal;

    Trie(){
        for(int i = 0;i<26;i++){
            child[i] = NULL;
        }
        isTerminal = false;
    }
    void insert(string word){
        Trie* current = this;
        for(char ch :word){
            int index = ch-'a';
            if(!current->child[index]) current->child[index] = new Trie();
            current = current->child[index];
        }
        current->isTerminal = true;
    }

    int check(string word){
        Trie* current = this;
        for(char ch :word){
            int index = ch-'a';
            if(!current->child[index]) return 0;
            current = current->child[index];
        }
        if(current->isTerminal){
            return 1;
        }
        return 0;

    }
};



class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int count = 0;

        Trie* t = new Trie();
        for(string s : bannedWords) t->insert(s);
        for(string b : message) count +=t->check(b);
        cout<<count;
        return count>=2;
    }
};