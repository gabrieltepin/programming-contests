#include <iostream>
typedef long long ll;
using namespace std;
ll sc(ll n){
	if (n<0) return 0;
	return (ll)((n+1)*(n+2)*(n+3))/6;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, A, B, C;
	ll S;
	cin >> T;
	//inclusion-exclusion principle and counting linear equation solutions:
	//Let SC(N+2, 2) the sum from N=0 to N of C(N+2, 2)
	//SC(N+2, 2) - SC(N+2-A,2) - SC(N+2-B,2) - SC(N+2-C,2) + SC(N+2-A -B,2)+
	//+SC(N+2-A-C,2) + SC(N+2-B-C,2) - SC(N+2-A-B-C,2)
	//Simplifying: SC(N+2, 2) = (N+1)(N+2)(N+3)/6;
	while(T--){
		cin >> N >> A >> B >> C;
		S=0;
		S+=sc(N);

		S-=sc(N-A-1);
		S-=sc(N-B-1);
		S-=sc(N-C-1);

		S+=sc(N-A-B-2);
		S+=sc(N-A-C-2);
		S+=sc(N-B-C-2);

		S-=sc(N-A-B-C-3);

		cout << S << "\n";
		
	}
	
	return 0;
}