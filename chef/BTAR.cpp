#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N; 
	ll x;
	cin >> T;
	while(T--){
		int num1=0, num2=0, num3=0, cont=0, sum =0;
		cin >> N;
		while(N--){
			cin >> x;
			if (x%4!=0){
				sum = (sum%4 + x%4)%4;
			}
			if(x%4==1)num1++;
			if(x%4==2)num2++;
			if(x%4==3)num3++;
		}
		if (sum%4!=0) cout << -1 << "\n";
		else {
			cont += min(num1, num3);
			num1 -= cont;
			num3 -= cont;

			cont += num1/2;
			num2 += num1/2;
			//num1 = 0;

			cont += num3/2;
			num2 += num3/2;
			//num3 = 0;

			cont += num2/2;
			//num2 = num2%2;
			cout << cont << "\n";
		}
	}	
	return 0;
}