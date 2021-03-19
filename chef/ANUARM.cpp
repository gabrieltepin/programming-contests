#include <iostream>
#include <algorithm>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, M, x;
	cin >> T;
	while(T--){
		int MIN=100007, MAX=-1;
		cin >> N >> M;
		fori (0, M){
			cin >> x;
			MIN = min(MIN, x);
			MAX = max(MAX, x);
		}
		fori(0, N){
			cout << max(abs(i-MAX), abs(i-MIN)) << " "; 
		}
		cout << "\n";
	}
	return 0;
}