#include <iostream>
#include <vector>
#include <queue>
//#include <tuple> , tuple for n ordered elements, pair for 2 ordered elements
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
int main() {
	while (1) {
		int n, b;
		cin >> n >> b;
		if (b == -1) break;
		vector<int> v(n);
		vector<int> c(n, 1);
		fori(0, n) cin >> v[i];
		//fori(0, a.size()) cout << c[i] << " "; cout << endl;
		priority_queue < pair <int, int> > q;
		fori(0, n) {
			//cout << (v[i] - 1) / c[i] + 1 << " " << i << endl; 
			q.push(make_pair((v[i] - 1) / c[i] + 1, i));
		}
		//cout << endl;
		//pair <int, int> topo;
		b -= n;
		while (b--) {
            //we could access second element with:
            //i = get<1>q.top()
            //we could access first element with:
            //i = get<0>q.top()
            //but get<n> makes more sense with tuples, so I will use first and second
            //as there are only pairs of elements
			int i = (q.top()).second;
			//topo = q.top();
			//cout << topo.first << " " << topo.second << endl;
			q.pop();
			c[i]++;
			q.push(make_pair((v[i] - 1) / c[i] + 1, i)); //ceil function
		}
		cout << (q.top()).first << endl;
	}
	return 0;
}