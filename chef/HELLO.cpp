#include <iostream>
#define fori(x, y) for(int i = x; i < y; ++i)
int main(){
	int T, U, N, M, C;
	double D, S, R;
	scanf("%d", &T);
	while(T--){
		scanf("%lf%d%d", &D,&U,&N);
		S = (double)D*U;
		int p = 0;
		fori(0, N){
			scanf("%d%lf%d", &M,&R,&C);
			double X = (C/(double)M) + R*U;
			if(S>X){
				S=X;
				p=i+1;
			}
		}
		printf("%d\n", p);
	}
	return 0;
}

