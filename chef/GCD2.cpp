#include <iostream>
#include <string>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std; 
int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, A;
	string B;
	cin >> T;
	while (T--){
		int num=0;
		cin >> A >> B;
		if (A==0) 
		    cout << B << "\n";
		else{
			fori(0,B.size()){
				num = (num*10 + (B[i]-'0'))%A;//exactly like the division 
				//algorithm, as we calculate in the paper
			}
			cout << gcd(A, num) << "\n";
		}
	}
	return 0; 
} 