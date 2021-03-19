#include <iostream>
#include <vector>
#include <algorithm>
#define fori(x, y) for(int i = x; i < y; ++i)
#define rfori(x, y) for(int i = x; i >= y; --i)
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> v(n), maxsofar(n), minsofar(n);
	fori(0, n){
		cin >> v[i];
	}
	maxsofar[0] = v[0];
	minsofar[n-1]=v[n-1];
	fori(1, n){
		maxsofar[i]=max(maxsofar[i-1], v[i]);
	}
	rfori(n-2, 0){
		minsofar[i]=min(minsofar[i+1], v[i]);
	}
	int cont=0;
	fori(0, n){
		if(v[i]>=maxsofar[i] && v[i]<=minsofar[i]) cont++;
	}
	cout << cont << "\n";
	return 0;
}
