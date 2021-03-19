#include <iostream>
#include <algorithm>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
typedef long long ll;
using namespace std;
int main() {
	int v1[801], v2[801], t, n;
	cin >> t;
	forj(1, t+1){
		ll P=0;
		cin >> n;
		fori(0, n){
			cin >> v1[i];
		}
		fori(0, n){
			cin >> v2[i];
		}
		sort(v1, v1+n);
		sort(v2, v2+n);
		fori(0, n){
			P+=(ll)v1[i]*v2[n-i-1];
		}
		cout << "Case #" << j << ": " << P << "\n";
	}
	return 0;
}