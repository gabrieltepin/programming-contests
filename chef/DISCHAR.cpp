#include <iostream>
#include <string>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T; 
	bool arr[256];
	string str;
	cin >> T;
	fori(0, T){
		int cont =0;
		fori(0, 257)arr[i]=0;
		cin >> str;
		fori(0, str.size()){
			if(arr[str[i]]==0){
				arr[str[i]]=1;
				cont++;
			}
		}
		cout << cont << "\n";

	}
	return 0;
}