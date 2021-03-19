#include <iostream>
#include <algorithm>
#include <cstring>
#define fori(x, y) for(int i = x; i < y; ++i)
#define TAM 314162
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, Q, L, X;
	ll row[TAM], col[TAM], MAXR=0, MAXC=0;
	string str;
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	cin >> N >> Q;
	fori(0, Q){
		cin >> str >> L >> X;
		if(str=="RowAdd"){
			row[L]+=X;
			MAXR=max(MAXR, row[L]);
		}
		if(str=="ColAdd"){
			col[L]+=X;
			MAXC=max(MAXC, col[L]);
		}
	}
	cout << MAXR+MAXC << "\n";
	return 0;
}