#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <unordered_map>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, hash;
	string s;
	while(cin >> n && n!=0){
		unordered_map <int, unordered_map < string, int > > umap;
		unordered_map <int, int> umap2;
		set <string> S;
		int col = 0;
		cin.ignore();
		forj(0, n){
			getline(cin, s);
			hash = s[0];
			fori(1, s.size()){
				hash ^= s[i];
			}
			if(umap.find(hash)==umap.end()){
				umap[hash][s]=1;
				umap2[hash]=1;
			}
			else{
				umap[hash][s]++;
				umap2[hash]++;
				col += umap2[hash] - umap[hash][s];
			}
			S.insert(s);
		}
		cout << S.size() << " " << col << "\n";
	}
	return 0;
}