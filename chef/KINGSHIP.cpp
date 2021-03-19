#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
#define rfori(x, y) for(int i = x; i >= y; --i)
#define INFLL numeric_limits<long long>::max()
#define INF numeric_limits<int>::max()
#define TAM 100007
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N, arr[TAM], indexMin;
	cin >> T;
	while(T--){
		ll sum = 0, MIN = INFLL;;
		cin >>N;
		fori(0, N){
			cin >> arr[i];
			if(MIN>arr[i]){
				MIN = arr[i];
				indexMin = i;
			}
		}
		fori(0, N){
			if(i!=indexMin) sum+=arr[i]*MIN;
		}
		cout << sum << "\n";
	}
	return 0;
}