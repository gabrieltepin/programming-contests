#include <iostream>
#include <string>
#include <unordered_map>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		char code[2];
		int cont=0;
		unordered_map <string, bool> umap;
		string str;
		cin >> str;
		fori(0, str.size()-1){
			code[0]=str[i];
			code[1]=str[i+1];
			if(umap[code]!=1) {
				cont++;
				umap[code]=1;
			}
		}
		cout << cont << "\n";
	}
	return 0;
}