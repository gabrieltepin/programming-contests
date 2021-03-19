#include <iostream>
#include <algorithm>
#define LIM 1000000007
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	ll x, y, z, tmp; 
	cin >> T;
	while(T--){
		cin >> x >> y >> z;
		//let's make x <= y <= z
		if(x>y) swap(x,y);
		if(x>z) swap(x,z);
		if(y>z) swap(y,z);
		tmp = ((x%LIM)*((y-1)%LIM))%LIM; 
		tmp = ((tmp%LIM)*((z-2)%LIM))%LIM;
		cout << tmp << "\n";
	}
	return 0;
}