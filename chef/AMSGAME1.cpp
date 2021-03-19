#include <iostream>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
int gcd(int a, int b){
	if (b==0) return a;
	return gcd(b, a%b);
} 
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, x;
	cin >> T;
	while (T--){
		int GCD =0;
		cin >> N;
		fori(0, N){
			cin >> x;
			GCD = gcd(x, GCD);
		}
		cout << GCD << "\n";
	}
	return 0; 
} 