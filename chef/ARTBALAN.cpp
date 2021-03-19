#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
#define TAM 26
#define LIM 214748360
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	string str;
	cin >> T;
	while(T--){
		int diffch=0, numch=0;
		vector <int> chind(TAM, -1), freq(TAM, 0), divisors;
		fori(0, TAM) chind[i]=-1;
		cin >> str;
		fori(0, str.size()){
			if(chind[str[i]-'A']==-1){
				freq[diffch]=1;
				chind[str[i]-'A'] = diffch++;
				numch++;
			}
			else{
				++freq[chind[str[i]-'A']];
				numch++;
			}
		}
		sort(freq.rbegin(), freq.rend());
		for(int i = 1; i*i <= numch; i++){
			if(numch%i == 0){
				divisors.push_back(i);
				if (numch/i != i) divisors.push_back(numch/i);
			}
		}
		int MIN = LIM;
		fori(0, divisors.size()){
			int n = numch/divisors[i];
			if(n<=26){
				int cont = 0;
				forj(0, n){
					if (divisors[i]>freq[j])
						cont+=divisors[i]-freq[j];
				}
				MIN = min(MIN, cont);
			}
		}
		cout << MIN << "\n";
	}
	return 0;
}