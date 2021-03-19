#include <iostream>
#include <unordered_map>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, x;
	cin >> T;
	while(T--){
		unordered_map <int, bool> umap;
		int cont = 0;
		cin >> N;
		fori(0, N){
			cin >> x;
			if(umap[x]!=1){
				umap[x]=1;
			}
			else cont++;
		}
		cout << cont << "\n";
	}
	return 0;
}