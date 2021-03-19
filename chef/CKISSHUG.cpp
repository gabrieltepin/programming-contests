#include <iostream>
#include <bitset>
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	ll N, x;
	cin >> T;
	while(T--){
		cin >> N;
		if(N%2 == 0) {
			x = 1<<((N/2)+1);
			x+= 1<<(N/2);
			x-= 2;
			cout << x << "\n";
		}
		else {
			x = 1<<((N+1)/2+1);
			x-= 2;
			cout << x << "\n";
		}
	}
	return 0;
}

