#include "bits/stdc++.h"
using namespace std;
#define M 6
class Graph{
    vector < vector <int> > adjList;
    int N;
public:
    Graph(int N): N(N){
        adjList.resize(N);
    }
    void link(int src, int dest){
        adjList[src].push_back(dest);
    }
    void print(){
        vector < vector<int> > :: iterator it1;
        vector<int> :: iterator it2;
        int n =0;
        for(it1=adjList.begin();it1!=adjList.end();it1++){
            cout << n++ << ": ";
            for(it2 = it1->begin(); it2!=it1->end();it2++){ //for(it2 = (*it1).begin(); it2!=(*it1).end();it2++){... } tambem serve
                cout << *it2 << " ";
            }
            cout << endl;
        }
    }
    void BFS(int x){
        cout << x << " --- ";
        queue < int > q;
        vector <int> :: iterator it;
        vector <bool> visited (M, false);
        q.push(x);
        int current;
        while (q.size()){
            current = q.front();
            q.pop();
            for(it = adjList[current].begin(); it != adjList[current].end(); it++){
                if(!visited[*it]){
                    q.push(*it);
                    visited[*it] = true;
                    cout << *it << " ";
                }
            }
        }
        cout << endl;
    }
    void DFSutil(int x, vector <bool> &visited){
        vector <int> :: iterator it;
        for (it = adjList[x].begin(); it!=adjList[x].end();it++){
            if(!visited[*it]){
                visited[*it] = true;
                cout << *it << " "; 
                DFSutil(*it, visited);
            }
        }
        return;
    }
    void DFS(int x){
        vector <int> :: iterator it;
        vector <bool> visited (M, false);
        DFSutil(x, visited);
    }
    
};
int main(){
    Graph G(M);

    G.link(1,2);
    G.link(2,3);
    G.link(3,4);
    G.link(4,1);
    G.link(2,4);
    G.link(3,4);
    G.link(0,0);
    G.link(0,4);
    G.link(0,2);
    G.link(0,1);
    G.link(2,0);
    G.link(2,2);

    G.print();

    G.BFS(2);
    G.BFS(3);
    G.BFS(1);

    G.DFS(2);




    return 0;
}