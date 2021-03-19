//manacher's algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        string T="";
        for(int i =0; i< s.size(); i++){
            T+="#";
            T+=s[i];
        }
        T+="#";
        vector <int> v(T.size());
        int C=0, R=0, maxlen=0, ini, end;
        for(int i = 0; i<T.size(); i++){
            int mirr = 2*C - i;
            if(i < R){
                v[i]=min(R-i, v[mirr]);   
            }
            while(i+v[i]+1<T.size()&&i-v[i]-1 >=0 &&T[i+v[i]+1]==T[i-v[i]-1]){
                v[i]++;
            }
            if(i+v[i]>R){
                C=i;
                R = i+v[i];
            }
            if(v[i]>maxlen){
                maxlen=v[i];
                ini = i-v[i];
                end = i+v[i];
            }
        }
        string ans="";
        for(int i = ini;i<=end;i++){
            if(T[i]!='#')ans+=T[i];
        }
        return ans;
        
    }
};