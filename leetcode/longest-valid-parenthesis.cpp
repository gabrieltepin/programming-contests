//it is not a solution because the sequence might not be centered in the middle
//for example, (())() max length is 6, not 4
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        for(int i = 0; i< s.size()-1; i++){
            int j=i, k=i+1, cont = 0, R=i;
            while(j>=0 && k<s.size() && s[j]!=s[k]){
                if(s[j]==')') cont--;
                if(s[j]=='(' && cont < 0)cont++;
                if(cont==0) R=k;
                j--;
                k++;
            }
            ans=max(ans, 2*(R-i));
            i=R;
        }
        return ans;
    }
};

//optimized solution
public class Solution {
    public int longestValidParentheses(String s) {
        int maxans = 0;
        int dp[] = new int[s.length()];
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == ')') {
                if (s.charAt(i - 1) == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s.charAt(i - dp[i - 1] - 1) == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = Math.max(maxans, dp[i]);
            }
        }
        return maxans;
    }
}

/*DP solution
This problem can be solved by using Dynamic Programming. We make use of a \text{dp}dp array where iith element of \text{dp}dp represents the length of the longest valid substring ending at iith index. We initialize the complete \text{dp}dp array with 0's. Now, it's obvious that the valid substrings must end with \text{‘)’}‘)’. This further leads to the conclusion that the substrings ending with \text{‘(’}‘(’ will always contain '0' at their corresponding \text{dp}dp indices. Thus, we update the \text{dp}dp array only when \text{‘)’}‘)’ is encountered.

To fill \text{dp}dp array we will check every two consecutive characters of the string and if

\text{s}[i] = \text{‘)’}s[i]=‘)’ and \text{s}[i - 1] = \text{‘(’}s[i−1]=‘(’, i.e. string looks like ``.......()" \Rightarrow‘‘.......()"⇒

\text{dp}[i]=\text{dp}[i-2]+2 dp[i]=dp[i−2]+2

We do so because the ending "()" portion is a valid substring anyhow and leads to an increment of 2 in the length of the just previous valid substring's length.

\text{s}[i] = \text{‘)’}s[i]=‘)’ and \text{s}[i - 1] = \text{‘)’}s[i−1]=‘)’, i.e. string looks like ``.......))" \Rightarrow‘‘.......))"⇒

if \text{s}[i - \text{dp}[i - 1] - 1] = \text{‘(’}s[i−dp[i−1]−1]=‘(’ then

\text{dp}[i]=\text{dp}[i-1]+\text{dp}[i-\text{dp}[i-1]-2]+2 dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2

The reason behind this is that if the 2nd last \text{‘)’}‘)’ was a part of a valid substring (say sub_ssub 
s
​	
 ), for the last \text{‘)’}‘)’ to be a part of a larger substring, there must be a corresponding starting \text{‘(’}‘(’ which lies before the valid substring of which the 2nd last \text{‘)’}‘)’ is a part (i.e. before sub_ssub 
s
​	
 ). Thus, if the character before sub_ssub 
s
​	
  happens to be \text{‘(’}‘(’, we update the \text{dp}[i]dp[i] as an addition of 22 in the length of sub_ssub 
s
​	
  which is \text{dp}[i-1]dp[i−1]. To this, we also add the length of the valid substring just before the term "(,sub_s,)" , i.e. \text{dp}[i-\text{dp}[i-1]-2]dp[i−dp[i−1]−2].
*/

public class Solution {
    public int longestValidParentheses(String s) {
        int maxans = 0;
        int dp[] = new int[s.length()];
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == ')') {
                if (s.charAt(i - 1) == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s.charAt(i - dp[i - 1] - 1) == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = Math.max(maxans, dp[i]);
            }
        }
        return maxans;
    }
}