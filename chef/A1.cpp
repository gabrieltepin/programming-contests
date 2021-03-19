#include <iostream>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
bool issum(int k, int N, int M, int* arr){
	if (M==0) return true;
	if (k>=N || M<0) return false;
	bool exc = issum(k+1, N, M, arr);
	bool inc = issum(k+1, N, M-arr[k], arr);
	return exc || inc;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, T, M, arr[27];
	cin >> T;
	while (T--){
		cin >> N >> M;
		fori(0, N){
			cin >> arr[i];
		}
		// .. It is Yes or No, not YES or NO!!!
		if(issum(0, N, M, arr)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}