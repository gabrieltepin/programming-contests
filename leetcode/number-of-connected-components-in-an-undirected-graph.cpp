class Solution {
public:
    int find (vector <int> &conex, int x){
        if(conex[x]==x) return x;
        return conex[x]=find(conex, conex[x]);
    }
    void link(vector<int>&conex, int a, int b, int &conexNum){
        int x = find(conex, a);
        int y = find(conex, b);
        if(x!=y) conexNum--;
        conex[x]=y;
        conex[y]=conex[x];
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector <int> conex(n);
        for(int i = 0; i<n; i++) conex[i]=i;
        int conexNum = n;
        for (auto edge: edges){
            link(conex, edge.first, edge.second, conexNum);
        }
        return conexNum;
    }
};