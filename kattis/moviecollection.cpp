#include <iostream>
#include <bitset>
#include <vector>
#define fori(x, y) for(int i = x; i < y; ++i)
#define TAM 1000007
using namespace std;
void update(int i, int val, int N, vector <int> &fT){
	while(i<=N){
		fT[i]+=val;
		i+=(i&(-i));
	}
}
int sum (int k, const vector <int> &fT){
	int ans =0;
	while(k>0){
		ans+=fT[k];
		k-=(k&(-k));
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, m, r, x, top, N;
	cin >> T;
	while (T--){
		cin >> m >> r;
		N = m+r;
		top = m;
		vector <int> fT(2*TAM, 0);
		vector <int> h(TAM);
		fori(1, m+1) h[i]=m-i+1;
		fori(1, m+1) update(i, 1, N, fT);
		while(r--){
			cin >> x;
			cout << sum(top, fT) - sum(h[x], fT) << " "; 
			update(h[x], -1, N, fT);
			h[x]=++top;
			update(top, 1, N, fT);
		}
		cout << "\n";
	}
	return 0;
}