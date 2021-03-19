#include <stdio.h>
typedef long long ll;
using namespace std;
int main(){
	int T;
	ll A, B, N, K, m, tmpA, tmpB, tmp;
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld%lld%lld", &N, &A, &B, &K);
		tmpA = A;
		tmpB = B;
		while(tmpB){
			tmp=tmpA;
			tmpA = tmpB;
			tmpB = tmp%tmpA;
		}
		m = A*B/tmpA;
		if(N/A - N/m + N/B - N/m >= K) printf("Win\n");
		else printf("Lose\n");
		
	}
	return 0;
}

