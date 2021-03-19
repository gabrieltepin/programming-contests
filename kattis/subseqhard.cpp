#include <iostream>
#include <vector>
#include <unordered_map>
#define fori(x, y) for(int i = x; i < y; ++i)
#define Find(x, y) y.find(x)!=y.end()
#define sum 47
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, t, x, r;
	cin >> t;
	while(t--){
		vector <ll> v;
		unordered_map <ll, int> umap;
		int cont=0;
		cin >> n;
		v.push_back(0);
		//umap[v[0]+sum]=1;
		while(n--){
			cin >> x;
			v.push_back(x);
		}
		fori(0, v.size()){
			if(i>0) v[i]+=v[i-1];
			if(Find(v[i], umap)) cont+=umap[v[i]];
			
			if(Find(v[i]+sum, umap)) umap[v[i]+sum]++;
			else umap[v[i]+sum]=1;
		}
		//fori(0, v.size()) cout << v[i] << " "; cout << endl;
		cout << cont << "\n";
	}
	return 0;
}