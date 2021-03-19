#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#include <iomanip>
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
	cin.tie(NULL); cout.tie(NULL);
	int N, T, arr[100007];
	cin >> T;
	while (T--){
		cin >> N;
		fori(0, N){
			cin >> arr[i];
		}
		fori(1, N){
			while(arr[i-1]){
				int tmp = arr[i-1];
				arr[i-1]=arr[i]%arr[i-1];
				arr[i] = tmp;
				//fori(0, N) cout << arr[i] << " ";		
			}
		}
		if(arr[N-1]==1) cout << N << "\n";
		else cout << -1 << "\n";
	}
	return 0;
}