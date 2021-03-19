//optimized memory solution
#include <iostream>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
#define TAM 1007
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, x[TAM], y[TAM]; 
	cin >> T;
	while(T--){
		int cont=0;
		char c;
		cin >> N;
		fori(0, N){
			x[i] = y[i] = 0;
		}
		fori(0, N){
			forj(0, N){
				cin >> c;
				if(c=='#'){
					x[i]=max(x[i], j+1); //cell blocked in line i
					y[j]=max(y[j], i+1); //cell blocked in col j
				}
			}
		}
		int S=0;
		fori(0, N){
			S+=x[i];
		}
		forj(0, N){
			int cont=0;
			if(y[j]>0){
				fori(0, y[j]){
					if(j<x[i])cont++;
				}
			}
			S+=y[j]-cont;
		}
		cout << N*N - S << "\n";
	}
	return 0;
}