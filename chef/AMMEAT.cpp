#include <iostream>
#include <algorithm>
#define fori(x, y) for(int i = x; i < y; ++i)
#define rfori(x, y) for(int i = x; i >= y; --i)
#define INF 2000000000
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N;
	ll M, arr[10];
	cin >> T;
	while(T--){
		ll sum=0;
		cin >> N >> M;
		fori(0, N){
			cin >> arr[i];
		}
		sort(arr, arr+N);
		rfori(N-1, 0){
			sum+=arr[i];
			if(sum>=M) {
				cout << N-i << "\n";
				break;
			}
			if(i==0 && sum <M){
				cout << -1 << "\n";
			}
		}
		
	}
	return 0;
}