#include <iostream>
#include <algorithm>
#include <string>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forik(x, y, k) for(int i = x; i < y; i+=k)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	string str;
	cin >> N;
	fori(0, N){
		int min0 = 0, min1 = 0, add0=0, add1 = 1;
		cin >> str;
		int tam = str.size();
		if(tam==1){
			cout << 0 << "\n";
		}
		else{
			forik(1, tam, 2){
				if(str[i]=='-') min1++;
			}
			add1=tam/2 - min1;
			
			forik(0, tam, 2){
				if(str[i]=='-') min0++;
			}
			add0=tam - (min1+add1+min0);
			
			cout << min(add0 + min1, add1 + min0) << "\n";
		}
	}
	
	return 0;
}

