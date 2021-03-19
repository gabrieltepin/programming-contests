#include <bits/stdc++.h>
using namespace std;
#define M 5
struct Node{
    vector <int> edges; //vertice's edges 
};

class Graph{
    Node* nodelist;
    const int N;
public:
    Graph(): N(M) {
        nodelist = new Node[N];
    }
    void join (int a, int b){
        nodelist[a].edges.push_back(b);
        //if it were undirect graph
        //nodelist[b].edges.push_back(a);
    }
    void print(){
        vector<int>::iterator it;
        for(int i =0; i<N;i++){
            cout << i << ": ";
            for(it = nodelist[i].edges.begin(); it!=nodelist[i].edges.end(); it++){
                cout <<  *it << " ";
            }
            cout << endl;
        }
    }

};

int main(){
    Graph G;
    G.join(2,3);
    G.join(1,4);
    G.join(4,2);
    G.join(1,2);
    G.join(0,3);
    G.join(2,4);
    G.print();
  
    return 0;
}