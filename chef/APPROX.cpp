#include <iostream>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, K, digit;
	cin >> T;
	while(T--){
		int p = 103993, q = 33102;
		cin >> K;
		//cout << fixed;
		//cout << setprecision(K) << N << "\n";
		if(K == 0) cout << 3 << "\n";
		else{ 
			cout << "3.";
			p%=q; //4687
			while(K--){
				p*=10;
				digit=p/q;
				p%=q;
				cout<<digit;
			}
			cout << "\n";
		}
	}
	return 0;
}