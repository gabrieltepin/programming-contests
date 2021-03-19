#include <iostream>
#include <vector>
#include <string>
#define fori(x, y) for(int i = x; i<y; i++)
using namespace std;
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int K, k=0, N;
	vector <string> sub;
	string str;
	cin >> K >> N;
	while(k++<K){
		cin >> str;
		sub.push_back(str);
	}
	while(N--){
		cin >> str;
		bool isfound=0;
		if(str.size()>=47) isfound=1;
		else
			fori(0,K){
				size_t found = str.find(sub[i]);
				if(found != string::npos) {
					isfound=1;
					i=K+1;
				}
			}
		if(isfound) cout << "Good\n";
		else cout << "Bad\n";
	}
	return 0; 
} 