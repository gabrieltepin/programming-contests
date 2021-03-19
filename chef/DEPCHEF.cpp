#include <iostream>
#include <vector>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
//careful (-1)%N == -1, not N-1  !!!!!!!!
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, x;
	cin >> T;
	while(T--){
		int inddef=-1;
		vector <int> a;
		cin >> N;
		fori(0, N) {
			cin >> x;
			a.push_back(x);
		}
		cin >> x;
		if(x > a[N-1] + a[1])
				inddef=max(x, inddef);
		fori(1, N-1) {
			cin >> x;
			if(x > a[i-1] + a[i+1])
				inddef=max(x, inddef);
		}
		cin >> x;
		if(x > a[N-2] + a[0])
				inddef=max(x, inddef);
		cout << inddef << "\n";
	}
	return 0;
}

