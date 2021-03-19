#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <unordered_map>
#include <math.h>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
#define rfori(x, y) for(int i = x; i >= y; --i)
#define Find(x, y) y.find(x)!=y.end()
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n, y1, y2;
	char p1, p2;
	cin >> n;
	while (n--){
		cin >> p1 >> y1 >> p2 >> y2;
		int x1, x2;
		x1 = p1-'A';
		x2 = p2-'A';
		if((x1+y1)%2 != (x2+y2)%2) cout << "Impossible\n";
		else {
			if (x1==x2 && y1 == y2) 
				cout << "0 " << p1 << " " << y1 << "\n";
			else if(y1-x1 == y2 - x2 || y1 + x1 == y2 + x2)
				cout << "1 " << p1 << " " << y1 << " " << p2 << " " << y2 << "\n"; 
			else {
				int r = (y2+x2-y1+x1)/2, c = (y2+x2+y1-x1)/2;
				if(r<=7 && r>=1 && c <= 7 && c >= 1){
					cout << "2 " <<  p1 << " " << y1 << " " << (char)('A' + r) << " " << c << " " << p2 << " " << y2 << "\n"; 
				}
				else{
					r = (y1+x1-y2+x2)/2;
					c = (y1+x1+y2-x2)/2;
					cout << "2 " <<  p1 << " " << y1 << " " << (char)('A' + r) << " " << c << " " << p2 << " " << y2 << "\n"; 
				}
			}
		}
	}
	return 0;
}
