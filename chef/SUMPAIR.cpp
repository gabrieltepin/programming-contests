#include <iostream>
#include <algorithm>
#include <vector>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, T, D;
	cin >> T;
	while(T--){
		long long sum = 0;
		cin >> N >> D;
		vector <int> v(N);
		fori(0, N){
			cin >> v[i];
		}
		sort(v.rbegin(), v.rend());
		fori(0, N-1){
			if(v[i] - v[i+1] < D){
				sum += v[i] + v[i+1];
				i++; //
			}
		}
		cout << sum << "\n";
		
	}
	
	return 0;
}

