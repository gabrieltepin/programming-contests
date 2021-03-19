#include <iostream>
#define fori(x, y) for(int i = x; i < y; ++i)
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, x;
	ll N;
	cin >> T;
	//xy > x + y <=> (x-1)(y-1)>1 <=> x,y>1 and x,y !=2
	while(T--){
		ll cont =0, cont2=0;
		cin >> N;
		fori(0, N){
			cin >> x;
			if(x==1 || x==0) ++cont;
			if(x==2) cont2++;
		}
		ll S = N*(N-1)/2 - N*cont + cont*(cont+1)/2;
		S-=cont2*(cont2-1)/2;
		cout << S << "\n";
	}
	return 0;
}