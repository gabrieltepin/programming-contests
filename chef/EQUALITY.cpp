#include <iostream>
#include <vector>
#define fori(x, y) for(int i = x; i < y; ++i)
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	ll N, a;
	cin >> T;
	while(T--){
		vector<ll> v;
		ll S=0;
 	 	cin >> N;
		fori(0, N){
			cin >> a;
			v.push_back(a);
			S+=a;
		}
		S/=(N-1);
		fori(0, N){
			cout << S - v[i] << " ";
		}
		cout << "\n";

	}
	return 0;
}

