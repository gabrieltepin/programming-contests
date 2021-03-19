#include <iostream>
#define fori(x, y) for(int i = x; i < y; ++i)
#define M 100007
typedef long long ll;
using namespace std;

int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, x; 
	ll N;
	cin >> T;
	while(T--){
		cin >> N;
		fori(0, N){
			cin >> x;
		}
		//integers are given distinct!
		cout << (N*(N-1))/2 << "\n";
	}
	return 0; 
} 