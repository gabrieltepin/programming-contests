#include <iostream>
#include <algorithm>
#include <vector>
#define fori(x, y) for(int i = x; i < y; ++i)
#define TAM 100007
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, K, P, y, i1, i2;
	ll x;
	vector < pair <ll, int> > v;
	int MAXDIST[TAM];
	cin >> N >> K >> P;
	fori(1, N+1){
		cin >> x;
		v.push_back(make_pair(x, i));
	}
	sort(v.rbegin(), v.rend());
	MAXDIST[v[0].second]=v[0].first+K;
	fori(1, N){
		if(v[i-1].first-v[i].first<=K){
			MAXDIST[v[i].second]=MAXDIST[v[i-1].second];
		}
		else {
			MAXDIST[v[i].second]=v[i].first+K;
		}
	}
	//fori(1, N+1) cout << MAXDIST[i] << " ";
	fori(0, P){
		cin >> i1 >> i2;
		if(MAXDIST[i1]==MAXDIST[i2]) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}