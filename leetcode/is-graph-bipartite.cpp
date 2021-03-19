class Solution {
public:
    bool isOk(vector<vector<int>>& graph, vector <int> &subset, int i){
        queue <int> q;
        q.push(i);
        if(subset[i]==-1) subset[i]=0;
        int t;
        while(!q.empty()){
            t = subset[q.front()]^1;
            for(int j = 0; j<graph[q.front()].size();j++){
                if(subset[graph[q.front()][j]]==-1) {
                    q.push(graph[q.front()][j]);
                    subset[graph[q.front()][j]]=t;
                }
                else{
                    if(subset[graph[q.front()][j]]!=t) return 0;
                }
            }
            q.pop();
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector <int> subset(graph.size(), -1);
        bool ans =1;
        for(int i = 0; i<graph.size();i++){
            ans = ans && isOk(graph, subset, i);
        }
        return ans;
    }
};

//optimized solution using union find
class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        rank = vector<int>(n, 1);
    }
    
    int findSet(int p) {
        int t = p;
        while (t != parent[t])
            t = parent[t];
        parent[p] = t;
        return t;
    }
    
    void unionSets(int a, int b) {
        int setA = findSet(a), setB = findSet(b);
        if (setA == setB)
            return;
        if (rank[setA] < rank[setB])
            swap(setA, setB);
        rank[setA] += rank[setB];
        parent[setB] = setA;
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if (!n)
            return 0;
        DisjointSet ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                if (ds.findSet(i) == ds.findSet(graph[i][j]))
                    return 0;
                if (j)
                    ds.unionSets(graph[i][j], graph[i][j - 1]);
            }
        }
        return 1;
    }
};