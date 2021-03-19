/*
tricky BFS
faltava sinalizar os digitos jah verificados
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define fori(x, y) for(int i = x; i < y; ++i)
#define TAM 100007
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	int N, distance[TAM], x;
	queue <int> q;
	vector <int> V[10];
	bool isvisited[10];
	fori(0, TAM) distance[i]=-1;
	fori(0, 10) isvisited[i]=0;
	cin >> str;
	N=str.size();
	fori(0, N) V[(int)(str[i]-'0')].push_back(i);
	q.push(0);
	while(distance[N-1]==-1){
		int ind = q.front();
		q.pop();
		x = (int)(str[ind]-'0');
		if(isvisited[x]==0){
			isvisited[x]=1;
			fori(0, V[x].size()){
				//cout << ind << " " << V[x][i] << endl;
				if(distance[V[x][i]]<0){
					q.push(V[x][i]);
					distance[V[x][i]]=distance[ind]+1;
				}
			}
		}
		if(ind>0 && distance[ind-1]<0){
			q.push(ind-1);
			distance[ind-1]=distance[ind]+1;
		}
		if(ind<N-1 && distance[ind+1]<0){
			q.push(ind+1);
			distance[ind+1]=distance[ind]+1;
		}
	}
	cout << distance[N-1] << "\n";
	return 0;
}
