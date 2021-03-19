#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
bool mycmp(pair <int, int> p , pair <int, int> q){
	if(p.first==q.first) return p.second>q.second;
	return p.first<q.first;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, T, x, y;
	cin >> T;
	while (T--){
		vector < pair < int, int > > v;
		cin >> N;
		fori(0, N){
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		sort(v.begin(), v.end(), mycmp);
		long double d=0;
		fori(1, N){
			d+=sqrt( (v[i].first-v[i-1].first)*(v[i].first-v[i-1].first) + 
			(v[i].second-v[i-1].second)*(v[i].second-v[i-1].second));
		}
		cout << fixed;
		cout << setprecision(2) << d << "\n";
	}
	return 0;
}