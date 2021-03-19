#include <iostream>
#include <algorithm>
#define fori(x, y) for(int i = x; i<y; i++)
#define rfori(x, y) for(int i = x; i>=y; i--)
typedef long long ll;
using namespace std;
int gcd (int x, int y){
	if (y==0) return x;
	return gcd(y, x%y);
}
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, T;
	ll arr[100007];
	cin >> T;
	while (T--){
		ll cont = 0;
		cin >> N;
		fori(0, N){
			cin >> arr[i];
		}
		sort(arr, arr+N);
		for(int i = N-1; i>=0; i-=2){
			cont+=arr[i];
		}
		cout << cont << "\n";
	}
	return 0; 
} 