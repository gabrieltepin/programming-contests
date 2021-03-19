#include <iostream>
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	ll i, j;
	cin >> N;
	while(N--){
		cin >> i >> j;
		int cont =0;
		while (i!=j){
			//cout << cont << " " << i << " " << j << "\n";
			if(i>j) i/=2;
			else j/=2;
			++cont;
		}
		cout << cont << "\n";
	}
	return 0;
}