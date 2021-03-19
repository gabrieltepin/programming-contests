class Solution {
public:
//if there aren't redundant edges, the number of judge's trusters is N-1
//we only need to check the one wich isn't self connected and with greater trusters
    int findJudge(int N, vector<vector<int>>& trust) {
        vector <bool> trustsomeone (N+1, 0);
        vector <int> trusted(N+1, 0);
        int judge=1, n=0;
        for(int i = 0;i<trust.size();i++){
            trustsomeone[trust[i][0]]=1;
            if(trust[i][0]!=trust[i][1]) trusted[trust[i][1]]++;
            if(trusted[trust[i][1]]>n){
                n=trusted[trust[i][1]];
                judge = trust[i][1];
            }
        }
        if(trustsomeone[judge]==1 || trusted[judge]!=N-1) return -1;
        return judge;
    }
};