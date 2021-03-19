#include <iostream>
#define TAM 100007
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, x;
	bool arr[TAM];
	cin >> T;
	while(T--){
		int S=0;
		cin >> N;
		fori(0, TAM) arr[i]=0;
		fori(0, N){
			cin >> x;
			if(arr[x]==0){
				++S;
				arr[x]=1;
			}
		}
		cout << S << "\n";
	}
	
	return 0;
}