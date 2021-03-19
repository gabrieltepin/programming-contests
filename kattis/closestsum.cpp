#include <iostream>
#include <algorithm>
#include <vector>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, cont = 1;
	long x;
	while(cin >> n){
		vector <long> v; 
		vector <long> sums;
		fori(0, n){
			cin >> x;
			v.push_back(x);
		}
		fori(0, n){
			forj(i+1, n){
				sums.push_back(v[i]+v[j]);
			}
		}
		sort(sums.begin(), sums.end());
		vector <long>:: iterator iter;
		cin >> m;
		cout << "Case " << cont++ << ":\n";
		while(m--){
			cin >> x;
			iter = lower_bound(sums.begin(), sums.end(), x);
			int pos = (int)(iter - sums.begin());
			if(pos>=sums.size()) pos--;
			if(pos>0 && abs(sums[pos-1]-x)<=abs(sums[pos]-x)) pos--;
			cout << "Closest sum to " << x << " is " << sums[pos] << ".\n";
		}
	}
	
	return 0;
}