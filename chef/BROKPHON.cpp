#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <limits>
#include <iomanip>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
#define rfori(x, y) for(int i = x; i >= y; --i)
#define INFLL numeric_limits<long long>::max()
#define INF numeric_limits<int>::max()
#define MININF numeric_limits<int>::min()
#define TAM 100007
#define LIM 1000000007
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N;
	ll arr[TAM];
	cin >> T;
	while(T--){
		int cont=0;
		cin >> N;
		fori(0, N){
			cin >> arr[i];
		}
		if(arr[0]!=arr[1])++cont;
		fori(1, N-1){
			if(arr[i-1]!=arr[i]||arr[i+1]!=arr[i]) ++cont;
		}
		if(arr[N-1]!=arr[N-2]) ++cont;
		cout << cont << "\n";
	}
	return 0;
}