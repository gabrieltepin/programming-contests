#include <iostream>
#define fori(x, y) for(int i = x; i < y; ++i)
#define TAM 1007
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, x[TAM], l[TAM], f[TAM];
	cin >> T;
	while(T--){
		cin >> N;
		fori(0, N){
			cin >> x[i] >> l[i] >> f[i];
		}
		int t =0;
		fori(0, N){
			if(t<x[i]) t = x[i]+l[i];
			else if(t%f[i]==x[i]%f[i]) t+=l[i];
			else{
				int q = (t-x[i])/(f[i]) + 1; 
				t=x[i] + f[i]*q + l[i];
			}
		}
		cout << t << "\n";
	}
	return 0;
}