#include <iostream>
#include <vector>
#include <queue>
#define fori(x, y) for(int i = x; i < y; ++i)
#define TAM 107
using namespace std;
struct P{
	int x;
	int y;
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, n, x, y;
	P p;
	cin >> T;
	while(T--){
		vector <P> v;
		vector <bool> isvisited(TAM, 0);
		queue <P> q;
		bool ishappy=0;
		cin >> n;
		fori(0, n+2) {
			cin >> p.x >> p.y;
			v.push_back(p);
		}
		q.push(v[0]);
		isvisited[0]=1;
		while(!q.empty() && ishappy==0){
			fori(1, n+2){
				int dist = abs(v[i].x-q.front().x)+abs(v[i].y-q.front().y);
				if(dist<=1000 && isvisited[i]==0){
					if(i==n+1){
						ishappy = 1;
						break;
					}
					q.push(v[i]);
					isvisited[i]=1;
				}
			}
			q.pop();
		}
		if(ishappy) cout <<"happy\n";
		else cout << "sad\n";
	}	
	return 0;
}