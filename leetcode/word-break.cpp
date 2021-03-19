class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> b(s.size()+1, 0);
        b[0]=1;
        unordered_set <string> dict;
        for (int i =0; i< wordDict.size(); i++){
            dict.insert(wordDict[i]);
        }
        for(int i =1; i<= s.size();i++){
            for(int j=0; j <=i; j++){
                if(dict.find(s.substr(i-j, j))!=dict.end()){
                    b[i]=b[i-j];
                    if(b[i]) break;
                }
                if(b[s.size()]) return 1;
            }
        }
        return b[s.size()];
    }
};


//////recursion with memoization
public class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        return word_Break(s, new HashSet(wordDict), 0, new Boolean[s.length()]);
    }
    public boolean word_Break(String s, Set<String> wordDict, int start, Boolean[] memo) {
        if (start == s.length()) {
            return true;
        }
        if (memo[start] != null) {
            return memo[start];
        }
        for (int end = start + 1; end <= s.length(); end++) {
            if (wordDict.contains(s.substring(start, end)) && word_Break(s, wordDict, end, memo)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }
}

//BFS
public class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> wordDictSet=new HashSet(wordDict);
        Queue<Integer> queue = new LinkedList<>();
        int[] visited = new int[s.length()];
        queue.add(0);
        while (!queue.isEmpty()) {
            int start = queue.remove();
            if (visited[start] == 0) {
                for (int end = start + 1; end <= s.length(); end++) {
                    if (wordDictSet.contains(s.substring(start, end))) {
                        queue.add(end);
                        if (end == s.length()) {
                            return true;
                        }
                    }
                }
                visited[start] = 1;
            }
        }
        return false;
    }
}