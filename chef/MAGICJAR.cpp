#include <iostream>
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N;
	ll x;
	cin >> T;
	while(T--){
		ll S=0;
		cin >> N;
		while(N--){
			cin >> x;
			S+=x-1;
		}
		cout << S+1 << "\n";
	}
	return 0;
}