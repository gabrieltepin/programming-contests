#include <iostream>
#include <vector>
#include <algorithm>
#define fori(x, y) for(int i = x; i < y; ++i)
#define TAM 100007
using namespace std;
int main(){
	int T, A, B, K;
	vector <int> v(TAM, 0);
	vector <int> numFactors[7];
	fori(2, TAM){
		if(v[i]==0){
			int tmp = i;
			while(tmp<=TAM){
				v[tmp]++;
				tmp+=i;
			}
		}
	}
	fori(2, TAM){
		numFactors[v[i]].push_back(i);
	}
	vector <int>::iterator l, h;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &A, &B, &K);
		l = lower_bound(numFactors[K].begin(), numFactors[K].end(), A);
		h = upper_bound(numFactors[K].begin(), numFactors[K].end(), B);
		printf("%d\n", (int)(h-l));
	}
	return 0;
}