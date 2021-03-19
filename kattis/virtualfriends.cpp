#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#define Find(x, y) y.find(x)!=y.end()
#define NotFind(x, y) y.find(x)==y.end()
using namespace std;
int fd(int i, vector <int> &S){
	int tmp =i;
	while(i!=S[i]){
		//path compression recursion
		i=fd(S[i], S);
	}
	S[tmp] = i;
	return i;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, f;
	string str1, str2;
	cin >> T;
	while(T--){
		unordered_map <string, int > umap;
		vector <int> rank;
		vector <int> S;
		int s = 0;
		cin >> f;
		while(f--){
			cin >> str1 >> str2;
			if(NotFind(str1, umap) && NotFind(str2, umap)){
				umap[str1] = umap[str2] = s;
				S.push_back(s++);
				rank.push_back(2);
				cout << 2 << "\n";
			}
			else if(Find(str1, umap) && NotFind(str2, umap)){
				umap[str2] = fd(umap[str1], S);
				rank[umap[str2]]+=1;
				cout << rank[umap[str2]] << "\n";
			}
			else if(NotFind(str1, umap) && Find(str2, umap)){
				umap[str1] = fd(umap[str2], S);
				rank[umap[str1]]+=1;
				cout << rank[umap[str1]] << "\n";
			}
			else{
				int rootx, rooty;
				rootx = fd(umap[str1], S);
				rooty = fd(umap[str2], S);
				if(rootx!=rooty){
					if(rank[rootx] >= rank[rooty]){
						umap[str2]=rootx;
						rank[rooty]+=rank[rootx];
						rank[rootx]=rank[rooty];
						//tava faltando soh atualizar o indicador no S
						S[rooty] = rootx;
						cout << rank[rootx] << "\n";
					}
					else {
						umap[str1]=rooty;
						rank[rooty]+=rank[rootx];
						rank[rootx]=rank[rooty];
						//tava faltando soh atualizar o indicador no S
						S[rootx] = rooty;
						cout << rank[rooty] << "\n";
					}
				}
				else{
					cout << rank[rootx] << "\n";
				}
			}
			
		}
	}
	return 0;
}