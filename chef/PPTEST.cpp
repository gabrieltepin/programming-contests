#include <iostream>
#include <vector>
#include <algorithm>
#define fori(x, y) for(int i = x; i < y; ++i)
#define rforj(x, y) for(int j = x; j >= y; --j)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, T, W, c, p, t, X[200];
	cin >> T;
	//just like knapsack problem
	while(T--){
	    vector < pair < int, int > > v;
		cin >> N >> W;
		fori(0, W+1) X[i]=0;
		fori(0, N){
			cin >> c >> p >> t;
			//first -> time, second -> cp
			v.push_back(make_pair(t, c*p));
		}
		//fori(0, N) cout << v[i].first << " " << v[i].second << endl;
		fori(0, N){
			rforj(W, 0){
				if(j-v[i].first>=0)
					X[j] = max(X[j], X[j-v[i].first]+v[i].second);
			}
			//fori(0, W+1) cout << X[i] << " "; cout << endl;
		}
		cout << X[W] << "\n";
	}
	return 0;
}

