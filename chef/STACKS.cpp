#include <iostream>
#include <algorithm>
#include <vector>
#define fori(x, y) for(int i = x; i < y; ++i)
#define LIM 1000000007
#define TAM 100000
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, x, idx;
	vector <int>::iterator hi;
	cin >> T;
	while(T--){
		int tam = 0;
		vector <int> v(TAM, LIM);
		cin >> N;
		fori(0, N){
			cin >> x;
			hi = upper_bound(v.begin(), v.begin()+N, x);
			int idx = hi - v.begin();
			v[idx]=x;
			tam = max(idx, tam);
			//fori(0, tam+1)cout << v[i] << " ";cout << endl;
		}
		cout << tam+1<< " ";
		fori(0, tam+1)cout << v[i] << " ";
		cout << "\n";
			
}
	return 0;
}