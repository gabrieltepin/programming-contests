#include <iostream>
#include <vector>
#include <string>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
int find(int N, vector <int> v){
	int a=0, b=v.size()-1, mid;
	while(a<=b){
		mid = (a+b)/2;
		//cout << mid << " " << trinum[mid];cout << endl;
		if(v[mid]>N){
			b=mid-1;
		}
		else if(v[mid]<N){
			a=mid+1;
		}
		else{
			a=mid+1;
			b=mid-1;
		}
	} 
	//cout << endl;
	if(v[mid]>N)--mid;
	return mid;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, x;
	vector <int> trinum;
	fori(0, 150){
		trinum.push_back((i*(i+1))/2);
	}
	cin >> T;
	while(T--){
		cin >> N;
		int mid;
		mid = find(N, trinum);
		int cont =0;
		char c = 'a';
		string ans;
		while(N){
			while(N>=trinum[mid]){
				//cout << N << " " << trinum[mid]; cout << endl;
				N-=trinum[mid];
				fori(0, mid){
					ans+=(char)(c+cont);
				}
				cont++;
			}
			mid = find(N, trinum);
		}
		if(cont>26) cout << -1 << "\n";
		else cout << ans << "\n";
	}
	return 0;
}