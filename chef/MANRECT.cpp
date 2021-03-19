#include <iostream>
#define L 1000000000
typedef long long ll;
using namespace std;
int main(){
	int T, N, isright;
	ll dl, dul, du, Px, Py, dP, Rx, Ry, dR, xu, yu, xl, yl;
	scanf("%d", &T);
	while(T--){
		//l : Yl = -x + dl
		printf("Q 0 0\n");
		fflush(stdout);
		scanf("%lld", &dl);

		//ul : Yul = x + L - dul
		printf("Q 0 1000000000\n");
		fflush(stdout);
		scanf("%lld", &dul);

		//let intersection point of Yl and Yul be P
		Px = (dl - L + dul)/2;
		if(Px<0) Px=0;
		Py = -Px + dl;
		printf("Q %lld %lld\n", Px, Py);
		fflush(stdout);
		scanf("%lld", &dP);
		xl = dP + Px;
		yl = dl - xl;

		//u : Yu = -x + 2l-du
		printf("Q 1000000000 1000000000\n");
		fflush(stdout);
		scanf("%lld", &du);

		//let intersection point of Yu and Yul be R
		Rx = (L - du + dul)/2;
		Ry = Rx + L - dul;
		if(Ry>L) Ry=L;
		printf("Q %lld %lld\n", Rx, Ry);
		fflush(stdout);
		scanf("%lld", &dR);
		yu = Ry - dR;
		xu = -yu + 2*L - du;

		printf("A %lld %lld %lld %lld\n", xl, yl, xu, yu); 
		fflush(stdout);
		scanf("%d", &isright);
		if(isright<0) return 0;
	}
	return 0;
}

