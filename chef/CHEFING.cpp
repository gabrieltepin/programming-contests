#include <iostream>
#include <string>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, l, arr[27], pos;
	string str;
	cin >> T;
	while(T--){
		int cont =0;
		fori(0, 27) arr[i] =0;
		cin >> N;
		fori(0, N){
			cin >> str;
			l = str.size();
			forj(0, l){
				pos = (int)(str[j]-'a');
				if(arr[pos]==i){
					arr[pos]++;
				}
			}
		}
		fori(0, 27) if(arr[i]==N) cont++;
		cout << cont << "\n";
	}
	return 0;
}

