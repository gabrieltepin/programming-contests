#include <iostream>
#define fori(x, y) for(int i = x; i < y; ++i)
#define M 100007
using namespace std;

int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, x;
	cin >> T;
	while(T--){
		cin >> N;
		int cont = 0;
		bool A[M] = {0};
		fori(0, N){
			cin >> x;
			if(A[x]==0) {
				cont++;
				A[x]=1;
			}
		}
		cout << cont << "\n";
	}
	return 0; 
} 