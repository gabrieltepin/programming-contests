//trick solution
int countSubstrings(string s) {
    int num = s.size();
    for(float center = 0.5; center < s.size(); center += 0.5) {
        int left = int(center - 0.5), right = int(center + 1);
        while(left >= 0 && right < s.size() && s[left--] == s[right++]) ++num;
    }
    return num;
}

//DP SOLUTION
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length(), res = 0;
        vector<vector<bool> > dp(len, vector<bool>(len, false));
        
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i; j < len; ++j) {
                dp[i][j] = (s[i] == s[j]) && (i + 1 > j - 1 || dp[i + 1][j - 1]);
                res += dp[i][j];
            }
        }
        
        return res;
    }
};

//O(N) solution using manacher's algorithm
class Solution {
public:
    int Manacher(string s) {
        const char kNullChar = '\0';
        string str = string(1, kNullChar);

        for(auto c: s) str += string(1, c) + kNullChar;

        string max_str = "";
        int len = str.size();
        int right = 0;
        int center = 0;
        vector<int> dp(len, 0);

        for(int i = 1; i < len; i++) {
            int mirr = 2*center - i;

            // i is within right so can take the minimum of the mirror or distance from right
            if(i < right) {
                dp[i] = min(right - i, dp[mirr]);
            }

            // keep expanding around i while it is the same and increment P[i]
            int left_index = i - (1 + dp[i]);
            int right_index = i + (1 + dp[i]);
            while(left_index != -1 && right_index != len && str[left_index] == str[right_index]) {
                left_index--;
                right_index++;
                dp[i]++;
            }

            // i goes beyond current right so it is the new center
            if(i + dp[i] > right) {
                center = i;
                right = i + dp[i];
            }
        }
        
        int count = 0;
        for(int i = 0; i < len; i++) {
            count += ceil((double)dp[i]/2.0);
        }
        return count;
    }

    int countSubstrings(string s) {
        return Manacher(s);
    }
};