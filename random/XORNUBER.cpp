#include <iostream>
#include <bitset>
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	ll N;
	cin >> T;
	while(T--){
		cin >> N;
		if (N==1) cout << 2 << "\n"; //M must be a positive integer
		else if((N&(N+1))==0) cout << N/2 << "\n";
		else cout << -1 << "\n";
	}
	
	return 0;
}