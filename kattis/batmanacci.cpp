#include <iostream>
#include <vector>
#define fori(x, y) for(int i = x; i < y; ++i)
#define INF 1000000000000100000LL //you need to write the LL so that it fits the longlong type
typedef long long ll;
using namespace std;
char getLetter(vector <ll> &v, ll n, ll k){
	if (n==1) return 'N';
	if (n==2) return 'A';
	char c;
	if(k>v[n-2]){
		c = getLetter(v, n-1, k - v[n-2]);
	}
	else{
		c = getLetter(v, n-2, k);
	}
	return c;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector <ll> v;
	ll n, k;
	cin >> n >> k;
	v.push_back(0);//s0
	v.push_back(1);//s1
	v.push_back(1);//s2
	fori(3, n+1){
		v.push_back(v[i-1]+v[i-2]);
		if(v[i]>INF) v[i]=INF;
	}
	cout << getLetter(v, n, k) << "\n";

	return 0;
}