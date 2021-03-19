#include <iostream>
#include <vector>
#include <algorithm>
#define fori(x, y) for(int i = x; i<y; i++)
#define rfori(x, y) for(int i = x; i>=y; i--)
typedef long long ll;
using namespace std;
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, arr[1001];
	cin >> T;
	while (T--){
		int sum =0;
		cin >> N;
		fori(0, N)
			cin >> arr[i];
		sort(arr, arr+N);
		rfori(N-1, 0){
			if(i>=0)
				sum+=arr[i];
			if(i-1>=0)
				sum+=arr[i-1];
			i-=3;
		}
		cout << sum << endl;

	}
	return 0; 
} 