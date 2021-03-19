#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x, ans;
	char op;
	string com, s;
	unordered_map <string, int> umap;
	unordered_map <int, string> umap2;
	while(cin >> com){
		if (com=="def"){
			cin >> s >> x;
			if(umap.find(s) != umap.end()) {
				int tmp = umap[s];
				umap.erase(s);
				umap2.erase(tmp);
			}
			umap[s] = x;
			umap2[x] = s;
		}
		if (com=="calc"){
			bool known = 1;
			cin >> s;
			cout << s << " ";
			if(umap.find(s) != umap.end()) {
				ans = umap[s];
			}
			else known = 0;
			while(cin >> op && op!='='){ 
				cin >> s;
				cout << op << " " << s << " ";
				if(umap.find(s) != umap.end() && op=='+') ans+= umap[s];
				if(umap.find(s) != umap.end() && op=='-') ans-= umap[s];
				if(umap.find(s) == umap.end()) known = 0;
			}
			if(umap2.find(ans) != umap2.end() && known) cout << "= " << umap2[ans] << "\n";
			else cout << "= unknown\n";
		}
		if (com=="clear"){
			umap.clear();
			umap2.clear();
		}
	}
	return 0;
}