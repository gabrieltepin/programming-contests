#include <iostream>
#include <vector>
#include <algorithm>
#define fori(x, y) for(int i = x; i < y; ++i)
#define MOD 1000000007
typedef long long ll;
using namespace std;
int main() {
	int n, A, B, C, t, solved=0;
    ll penalty=0, T=0;
	cin >> n >> t;
	vector <ll> v(n);
	cin >> A >> B >> C >> v[0];
	fori(1, n)
		v[i]=((A%C)*(v[i-1]%C)+(B%C))%C+1;
	sort(v.begin(), v.end());
	fori(0, n){
		if(T+v[i]<=t) {
			solved++;
			penalty=(v[i]%MOD+T%MOD+penalty%MOD)%MOD;
			T+=v[i];
		}
		else break;
	}
	cout << solved << " " <<  penalty << "\n";
	return 0;
}