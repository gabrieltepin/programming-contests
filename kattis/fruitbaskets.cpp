#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
#define fork(x, y) for(int k = x; k < y; ++k)
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector <ll> v;
	ll n, x, sum=0, comb[41];
	cin >> n;
	//comb = 1<<(n-1); gives overflow if n >= 32..
	comb[0]=1;
	fori(1, n)
		comb[i] = comb[i-1]<<1;
	fori(0, n){
		cin >> x;
		sum+=(ll)x*comb[n-1];
		v.push_back(x);
	}
	//as x > 50, 4 distincts elements's sum must be larger than 200, so we can 
	//find the total weights by excluding those that don't fit.
	//Note that if it doesn't fit, then it must have at most 3 elements
	ll curr;
	fori(0, v.size()){
		curr = v[i];
		if(curr<200) sum-=curr;
		forj(i+1, v.size()){
			curr = v[i]+v[j];
			if(curr<200) sum-=curr;
			fork(j+1, v.size()){
				curr = v[i]+v[j]+v[k];
				if(curr<200) sum-=curr;
			}
		}
	}
	cout << sum << "\n";
	return 0;
}