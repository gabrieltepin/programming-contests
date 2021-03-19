class Solution {
private:
    unordered_map <int, int> umap;
public:
    bool auxCanCross(vector<int> & stones, vector <vector <int> > &dp, int N, int k){
        if(N==stones[stones.size()-1]) return true;
        if(k<=0 || N>stones[stones.size()-1] || umap.find(N)==umap.end()) return false;
        if(dp[umap[N]][k]!=-1) return dp[umap[N]][k];
        dp[umap[N]][k] = auxCanCross(stones, dp, N+k, k) || auxCanCross(stones, dp, N+k-1, k-1) || auxCanCross(stones, dp, N+k+1, k+1);
        return dp[umap[N]][k];
    }
    bool canCross(vector<int>& stones) {
        int length = stones.size()-1;
        vector < vector <int> > dp(stones.size()+1, vector<int> (stones.size()+1, -1));
        for(int i = 0;i<stones.size();i++)
            umap[stones[i]]=i;
        return auxCanCross(stones, dp, 1, 1);
    }
};