#include <iostream>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
#define fork(x, y) for(int k = x; k < y; ++k)
#define TAM 251
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, S, G, D;
	cin >> N;
	ll T[TAM][TAM];
	fori(0, N)
		forj(0, N)
			cin >> T[i][j];
	fork(0, N){
		fori(0, N){
			forj(0, N){
				if(T[i][j]>T[i][k]+T[k][j])
					T[i][j] = T[i][k]+T[k][j];
			}
		}
	}
	cin >> M;
	while(M--){
		cin >> S >> G >> D;
		cout << T[S][G]+T[G][D] << " " << T[S][G]+T[G][D]-T[S][D] << "\n";
	}
	return 0;
}