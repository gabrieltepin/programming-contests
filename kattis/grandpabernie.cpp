#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	unordered_map <string, vector<int> > umap;
	int n, yr, q, t;
	string s;
	cin >> n;
	while(n--){
		cin >> s >> yr;
		umap[s].push_back(yr);
	}
	unordered_map <string, vector<int> >::iterator it;
	for (it = umap.begin(); it != umap.end(); ++it){
		sort((it->second).begin(), (it->second).end());
	}
	cin >> q;
	while(q--){
		cin >> s >> t;
		cout << umap[s][t-1] << "\n";
	}

	return 0;
}