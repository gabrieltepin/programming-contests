#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <algorithm>
#define Find(x, y) y.find(x)!=y.end()
#define NotFind(x, y) y.find(x)==y.end()
#define fori(x, y) for(int i = x; i < y; ++i)
#define INF 1000000
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, cont = 0, x;
	char op;
	string str;
	unordered_map <string, int> umap;
	stack <string> stk;
	cin >> N;
	while(N--){
		cin >> op;
		if(op == 'E'){
			cin >> str;
			umap[str]=++cont;
			stk.push(str);
		}
		else if(op == 'D'){
			cin >> x;
			fori(0, x){
				umap.erase(stk.top());
				stk.pop();
				cont--;
			}
		}
		else {
			cin >> x;
			bool yes=1, ploterror=0;
			int rmv=0, r=INF, pos=0; 
			while(x--){
				cin >> str;
				if(str[0]=='!') {
					str = str.substr(1);
				 	if(Find(str, umap)){
						yes = 0;
						r = min(r, umap[str]);
					}
					//else if(NotFind(str, umap)) YES
				}
				else{
					if(Find(str, umap)){
						pos = max(pos, umap[str]);
					} 
					else if(NotFind(str, umap)){
						ploterror=1;
					}
				}
			}
			if (pos >= r) ploterror = 1;
			if(ploterror) cout << "Plot Error\n";
			else {
				if(yes) cout << "Yes\n";
				else {
					rmv = max(cont-r+1, rmv);
					cout << rmv << " Just A Dream\n";
				}
			}
		}
	}
	return 0;
}