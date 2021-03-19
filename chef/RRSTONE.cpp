#include <iostream>
#include <algorithm>
#define fori(x, y) for(int i = x; i < y; ++i)
#define M 100007
#define INF 40000000000
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N, K, MIN = INF, MAX=0, arr[M];
	cin >> N >> K;
	fori(0, N){
		cin >> arr[i];
		MAX = max(arr[i], MAX);
		MIN = min(arr[i], MIN);
	}
	if(K==0){
		fori(0, N){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else if(K%2==1){
		fori(0, N){
			cout << MAX - arr[i] << " ";
		}
		cout << "\n";
	}
	else{
		fori(0, N){
			cout << arr[i] - MIN << " ";
		}
		cout << "\n";
	}
	return 0;
}