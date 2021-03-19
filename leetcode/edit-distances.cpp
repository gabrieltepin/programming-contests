class Solution {
public:
    int minDistance(string word1, string word2) {
        vector < vector <int> > lookup (word1.size()+1, vector <int> (word2.size()+1));
        for(int i = 0; i<=word1.size(); i++) //from nothing to form word1, it requires word1.size() op
            lookup[i][0] = i;
        for(int i = 0; i<=word2.size(); i++) //from nothing to form word2, it requires word2.size() op
            lookup[0][i] = i;
        for(int i = 1; i<word1.size()+1; i++){
            for(int j = 1; j<word2.size()+1; j++){
                if(word1[i-1]==word2[j-1]){
                    lookup[i][j] = lookup[i-1][j-1];
                }   
                else{
                    lookup[i][j] = 1+min(lookup[i-1][j], min(lookup[i][j-1], lookup[i-1][j-1]));
                }
            }
        }
        return lookup[word1.size()][word2.size()];
    }
};

//java dp memoization solution
public int minDistance(String word1, String word2) {
    int m = word1.length();
    int n = word2.length();
    dp = new int [m+1] [n+1];
    return editDist(word1,word2,m,n);
}

int editDist(String str1 , String str2 , int m ,int n){
    int result;
    if(dp[m][n] !=0)
        return dp[m][n];

    if(m==0)
        return n;
    if(n==0)
        return m;
    if (str1.charAt(m-1) == str2.charAt(n-1)) {
        result= editDist(str1, str2, m-1, n-1); 
    }
    else{
        result =  1 + Math.min (
                 Math.min(editDist(str1,  str2, m, n-1),    // Insert 
                 editDist(str1,  str2, m-1, n)),   // Remove 
                 editDist(str1,  str2, m-1, n-1) // Replace                      
               ); 
     }
    
    dp [m][n] =result;
    return result;
 }