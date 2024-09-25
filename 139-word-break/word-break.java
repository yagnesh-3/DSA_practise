class Solution {
    class Trie {
        Trie[] children = new Trie[26];
        boolean endOfWord;

        Trie() {
            for (int i = 0; i < 26; i++) children[i] = null;
            endOfWord = false;
        }

        void insertWord(String word) {
            Trie current = this;
            for (int i = 0; i < word.length(); i++) {
                int index = word.charAt(i) - 'a';
                if (current.children[index] == null) current.children[index] = new Trie();
                current = current.children[index];
            }
            current.endOfWord = true;
        }

        boolean searchWord(String word, int start, boolean[] dp, Trie root) {
            if (!dp[start]) return false;
            Trie current = this;
            for (int i = start; i < word.length(); i++) {
                int index = word.charAt(i) - 'a';
                if (current.children[index] == null) break;
                current = current.children[index];
                if (current.endOfWord) {
                    if (i == word.length() - 1 || root.searchWord(word, i + 1, dp, root)) return true;
                }
            }
            dp[start] = false;
            return false;
        }
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        Trie root = new Trie();
        for (String word : wordDict) root.insertWord(word);
        boolean[] dp = new boolean[s.length() + 1];
        for (int i = 0; i < dp.length; i++) dp[i] = true;
        return root.searchWord(s, 0, dp, root);
    }
}